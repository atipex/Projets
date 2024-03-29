#!/usr/bin/python
#
# Made by duponc_j@epitech.net
# Version: 1.2.1
#

'''
An Epitech norme checker

Usage: python norme.py <files to scan> [-nocheat] [-verbose] [-score] [-libc]

-verbose: affiche les messages impossible d\'ouvrir
-nocheat: desactive la detection de la triche
-score: affiche le nombre de faute de norme
-libc: active la verification des fonctions de la libc
-malloc: desactive le controle du malloc
-printline: affiche la ligne provoquant une erreur
-return: active verifier le retour des fonctions (return ;)
-comment: ne pas verifier les commentaire

Non geree:
- Indentation
- +<escape>
- verification de la presence de gl_
_ macro multiligne
_ initialisation de variable a la declaration
_ separation initialisation de variable et code

A modifier:
Fonction checkant la protection contre la double inclusion des .h .
Appel ligne 163.

Bug:
Il est arrivee que le checker ne trouve aucune faute alors qu\'il en existe, si
ce bug vous arrive maillez moi.
'''

import sys,re,os,pwd

version = 0.5

class norme:
    def __init__(self):
        self.user = []
        self.verbose = 0
        self.glob = 1
        self.cheat = 1
        self.comment = 1
        self.score = 1
        self.note = 0
        self.libc = 1
        self.printline = 0
        self.creturn = 1

    def new_file(self):
        self.nb_line = 1
        self.nb_return = 0
        self.nb_funcline = 0
        self.nb_func = 0
        self.sys_include = 0
        self.double_inclusion = 0
        self.is_func = 0
        self.typedef = 0
        self.init_ext = 0
        if self.verbose == 1:
            print "-->Scan",self.file

#    def check_header(self):
#        if (self.nb_line == 1):
#            if (self.line[:2] != '/*'):
#                self.print_error('header incorrect')
#                self.note += 20
#        elif (self.nb_line == 9):
#            if (self.line[:2] != '*/'):
#                self.print_error('header incorrect')
        # elif self.nb_line == 4 or self.nb_line == 7 or self.nb_line == 8:
        #     if self.cheat:
        #         p = re.compile('([\w-]* [\w-]*)$')
        #          test = re.search(p, self.line)
        #         if test:
        #             if not test.group(1) in self.user:
        #                 self.print_error('login '+ test.group(1) +' incorrect')
        #                  print "Note: -42"
        #                  sys.exit()
        # elif (self.nb_line == 5):
        #     if self.cheat:
        #         p = re.compile('<(.*)@')
        #         test = re.search(p, self.line)
        #         if test:
        #             if not test.group(1) in self.user:
        #                 self.print_error('login '+ test.group(1) +' incorrect')
        #                 print "Note: -42"
        #                 sys.exit()
 #       else:
 #           if (self.line[:2] == '**'):
 #               self.print_error('header incorrect')

    def check_virgule(self):
        if is_commented(self.line) == False:
            n = 0
            quote = 0
            while self.line[n] != '\n':
                if self.line[n] == '\'' or self.line[n] == '"' and self.line[n - 1] != '\\':
                    if quote:
                        quote = 0
                    else:
                        quote = 1
                if (self.line[n] == ';' or self.line[n] == ',') and quote == 0:
                    if self.line[n + 1] != ' ' and self.line[n + 1] != '\n':
                        self.note += 1
                        self.print_error('point-virgule ou virgule mal place')
                n = n + 1

    def check_nbchar(self):
        line = self.line.replace('\t', '    ')
        if (line[80:]):
            self.note += 1
            self.print_error('chaine de plus de 80 caracteres')

    def check_struct(self):
        p = re.compile('struct')
        test = re.search(p, self.line)
        if test:
            p = re.compile('s_')
            test = re.search(p, self.line)
            if not test:
                self.note += 1
                self.print_error('s_ manquant avant une struct')
    def check_return(self):
        if (self.line[:1] == '\n'):
            if (self.nb_return == 1):
                self.note += 1
                self.print_error('double retour a la ligne')
            else:
                self.nb_return = 1
        else:
            self.nb_return = 0

    def check_nbline(self):
        if self.file[-2:] == ".c":
            if self.line[:1] == '}' and self.is_func == 1:
                self.is_func = 0
                self.nb_funcline = 0
            elif self.line[:1] == '}' and self.typedef == 1:
                self.typedef = 0
                p = re.compile('t_')
                test = re.search(p, self.line)
                if self.glob:
                    if test:
                        self.print_error('t_ manquant devant un typedef')
                        self.note += 1
                else:
                    self.init_ext = 0
            p = re.compile('{')                                                                                                                                                                                                       
            test = re.search(p, self.line) 
            if self.line[:1] == '{' and self.typedef == 0:
                self.is_func = 1
                self.nb_funcline = 0
                self.nb_func = self.nb_func + 1
                if self.nb_func == 6:
                    self.note += 1
                    self.print_error('plus de 5 fonctions dans le fichier')
            elif test:
                self.init_ext = 1;
            else:
                if self.nb_func >= 1 and self.is_func:
                    self.nb_funcline = self.nb_funcline + 1
                    if self.nb_funcline >= 26:
                        self.note += 1
                        self.print_error('fonction de plus de 25 lignes')

    def check_cfunc(self):
        if is_commented(self.line) == False:
            p = re.compile('[ \t](if|else|return|while|for)(\()')
            test = re.search(p, self.line)
            if test:
                self.note += 1
                self.print_error('pas d\'espace apres mot clef')

    def check_arg(self):
        if self.line[-2:] == ")\n" and self.line[:1] != '\t'  and self.line[:1] != ' ':
            p = re.compile('(.*),(.*),(.*),(.*),(.*)\)$')
            test = re.search(p, self.line)
            if test:
                self.note += 1
                self.print_error('plus de 4 arguments passes en parametre')

#    def heck_sys_include(self):
#        if self.line[:1] == "#" and self.line[-2:] == "\"\n":
#            self.sys_include = 1
#        else:
#            if self.line[:1] == "#" and self.line[-2:] == ">\n" and self.sys_include == 1:
#                self.note += 1
#                self.print_error('Header systeme mal placee')

    def check_comment(self):
        if self.is_func and self.comment:
            p = re.compile('(//|/\*)')
            test = re.search(p, self.line)
            if test:
                self.note += 1
                self.print_error('Commentaires dans le code')

    def check_global(self):
        if self.is_func == 0 and self.typedef == 0 and self.init_ext == 0\
                and self.line[:1] != "#" and self.line != "\n" and self.line[:1] != "}" \
                and self.line[-2:] != ")\n" and self.line[-3:] != ");\n":
            p = re.compile('g_')
            test = re.search(p, self.line)
            if not test:
                self.note += 1
                self.print_error('Global ne commencent pas par g_')
    

    def check_malloc(self):
        p = re.compile('[^x](malloc)(\()')
        test = re.search(p, self.line)
        if test and (self.file != "xmalloc.c"):
            self.print_error('Malloc non verifiee')
            self.note += 1

    def check_operateur(self, op):
        n = 0
        quote = 0
        while self.line[n] != '\n':
            if self.line[n] == '\'' or self.line[n] == '"' and self.line[n - 1] != '\\':
                if quote:
                    quote = 0
                else:
                    quote = 1
            if (self.line[n] == op) and quote == 0:
                if self.line[n + 1] != ' ' and self.line[n + 1] != ';' and self.line[n + 1] != '=':
                    if self.line[n - 1] != op and self.line[n + 1] != op:
                        msg = 'Operateur %c mal place' % op
                        self.print_error(msg)
                        self.note += 1
            n = n + 1

    def check_typedef(self):
        if self.line[:7] == "typedef":
            self.typedef = 1
            if self.glob:
                if self.line[-2:] == ";\n":
                    p = re.compile('t_')
                    test = re.search(p, self.line)
                    if not test:
                        self.print_error('t_ manquant devant un typedef')
                        self.note += 1

    def check_regex(self, regex, msg):
        p = re.compile(regex)
        test = re.search(p, self.line)
        if test:
            self.note += 1
            self.print_error(msg)

    def check_line(self):
        if is_commented(self.line) == False:
            self.check_nbline() # DOIT TOUJOURS ETRE EN PREMIER
            #self.check_sys_include()
            self.check_virgule()
            self.check_regex('[ \t]$', 'Espace en fin de ligne')
            if self.creturn == 0:
                self.check_regex('return( \(\)| ;|;)', 'Mauvais format de return')
            if self.libc == 0:
                self.check_regex('[^_](printf|atof|atoi|atol|strcmp|strlen|strcat|strncat|strncmp|strcpy|strncpy|fprintf|strstr|strtok|sprintf|asprintf|perror|strtod|strtol|strtoul)(\()', \
                             'Fonction de la lib C')
            self.check_nbchar()
            self.check_cfunc()
            if self.glob:
                self.check_struct()
            self.check_arg()
            self.check_comment()
            self.check_return()
            self.check_operateur('+')
            self.check_operateur('|')
            self.check_typedef() #doit etre a la fin            
            if self.glob:
                self.check_global() #doit etre apres typedef

    def print_error(self, msg):
        print "Erreur dans\033[31m",self.file,"\033[0ma la ligne\033[31m",self.nb_line,"\033[0m:\033[33m",msg,"\033[0m"
        if self.printline:
            print self.line

    def cant_open(self, file):
        if (self.verbose):
            print "Impossible d'ouvrir",file

    def scan_files(self, files):
        for file_name in files:
            self.file = file_name
            self.new_file()
            try:
                fd = open(file_name, 'r')
            except IOError:
                self.cant_open(file)
            else:
                for self.line in fd.readlines():
                    if self.nb_line <= 9:
                   #     self.check_header()
                        self.check_line()
                    else:
                        self.check_line()
                    self.nb_line = self.nb_line + 1
                fd.close()

    def scandir(self, thedir):
        try:
            dir = os.listdir(thedir)
        except:
            self.cant_open(thedir)
        else:
            if self.verbose == 1:
                print "Check du dossier", thedir
            check_makefile(thedir)
            for file in dir:
                if (os.path.isdir(thedir + file)):
                    self.scandir(thedir + "/" + file + "/")
                if file[-2:] == '.c' or file[-2:] == '.h':
                    self.file = file
                    self.new_file()
                    file = thedir + file
                    try:
                        fd = open(file, 'r')
                    except IOError:
                        self.cant_open(file)
                    else:
                        for self.line in fd.readlines():
                            if self.nb_line <= 9:
                               # self.check_header()
                                self.check_line()
                            else:
                                self.check_line()
                            self.nb_line = self.nb_line + 1
                            fd.close()

# Trouve le login dans la variable $MOULINETTE_USER et va chercher
# le nom complet dans /afs/epitech.net/site/etc/passwd
# Si pas de variable $MOULINETTE_USER va chercher $USER
    def get_user(self):
         self.user.append("carpen_t")
        # user_list = []
        # user = os.getenv('MOULINETTE_USER')
        # if user:
        #     user_list = user.split(';')
        # if not user:
        #     user_list.append(os.getenv('USER'))
        # for user_name in user_list:
        #     f = open("/afs/epitech.net/site/etc/passwd", 'r')
        #     while 1:
        #         line = f.readline()
        #         if line:
        #             line = line.split(':')
        #             if user_name == line[0]:
        #                 break
        #         if not line:
        #             f.close()
        #             return
        #     f.close()
        #     self.user.append(user_name)
        #     self.user.append(line[4])

def check_makefile(thedir):
    file = thedir + "Makefile"
    if os.path.isfile(file):
        try:
            fd = open(file, 'r')
        except IOError:
            print "Impossible d'ouvrir le Makefile"
        else:
            buffer = fd.read()
            p = re.compile('(-g|-pg|-lefence)')
            test = re.search(p, buffer)
            if test:
                print "Options de debug dans le Makefile :", file
            p = re.compile('(-Wall)')
            test = re.search(p, buffer)
            if not test:
                print "Wall n'est pas dans le Makefile :", file
          #  p = re.compile('(-pedantic)')
          #  if buffer[:2] != "##":
          #      print "Header du Makefile invalide"
            fd.close()

def get_files(argv):
    li = []
    pattern = re.compile('[.]c$|[.]h$')
    for arg in sys.argv:
        test = re.search(pattern, arg)
        if test:
            li.append(arg)
    return li

def is_commented(line):
    if ((line[0] == '/' or line[0] == '*') and line[1] == '*'):
        return True
    return False

def check_version():
    file = "/afs/epitech.net/users/prof/astek/public/norme_version"
    if os.path.isfile(file):
        try:
            fd = open(file, 'r')
        except IOError:
            print "Impossible de verifier la version du script"
        else:
            buffer = fd.read()
            if (version != float(buffer)):
                print "Mauvaise version du script, verifiez sur le public astek"

def help():
    print "Aide"
    print "Moulinette version " + str(version)
    print "Usage: norme.py <files_to_scan>"
    print "-verbose: affiche les messages impossible d'ouvrir"
    print "-nocheat: desactive la detection de la triche"
    print "-score: affiche le nombre de faute de norme"
    print "-libc: active la verification des fonctions de la libc"
    print "-printline: affiche la ligne provoquant une erreur"
    print "-return: active verifier le retour des fonctions (return ;)"
    print "-comment: ne pas verifier les commentaires"
    sys.exit()

def main():
    if '-help' in sys.argv[1:]:
        help()
    check_version()
    # if len(sys.argv) == 1:
    #     print "Usage: norme.py <files_to_scan>"
    #     sys.exit()
    moulin = norme()
    # files = get_files(sys.argv)
    if '-verbose' in sys.argv[1:]:
        moulin.verbose = 1
    if '-comment' in sys.argv[1:]:
        moulin.comment = 0
    # if '-nocheat' in sys.argv[1:]:
    moulin.cheat = 0
    if '-score' in sys.argv[1:]:
        moulin.score = 1
    if '-libc' in sys.argv[1:]:
        moulin.libc = 0
    if '-nostruct' in sys.argv[1:]:
        moulin.glob = 0
    if '-printline' in sys.argv[1:]:
        moulin.printline = 1
    if '-return' in sys.argv[1:]:
        moulin.creturn = 0
    # if moulin.cheat == 1:
    #     moulin.get_user()
    moulin.scandir("./")
    if moulin.score:
        print "\033[31mNote:",-moulin.note,"\033[0m"

if __name__ == "__main__":
    main()
