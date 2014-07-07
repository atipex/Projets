SELECT UPPER(fiche_personne.nom) as `NOM`, fiche_personne.prenom, abonnement.prix from fiche_personne, abonnement, membre WHERE membre.id_abo = abonnement.id_abo AND fiche_personne.id_perso = membre.id_membre AND prix > 42 ORDER BY nom,prenom ASC;
