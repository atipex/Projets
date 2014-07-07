-- phpMyAdmin SQL Dump
-- version 4.1.9
-- http://www.phpmyadmin.net
--
-- Client :  localhost:3306
-- Généré le :  Ven 04 Avril 2014 à 21:57
-- Version du serveur :  5.5.36
-- Version de PHP :  5.4.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `my_boutique`
--
-- DROP DATABASE `my_boutique`;

-- --------------------------------------------------------

--
-- Structure de la table `articles`
--

CREATE TABLE IF NOT EXISTS `articles` (
  `id_article` int(11) NOT NULL AUTO_INCREMENT,
  `id_menu2` int(11) NOT NULL,
  `design` varchar(254) DEFAULT NULL,
  `ref` varchar(254) DEFAULT NULL,
  `stock` int(11) DEFAULT NULL,
  `vignette` blob,
  `prix` float DEFAULT NULL,
  PRIMARY KEY (`id_article`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

CREATE TABLE IF NOT EXISTS `client` (
  `id_client` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(254) DEFAULT NULL,
  `prenom` varchar(254) DEFAULT NULL,
  `login_client` varchar(254) DEFAULT NULL,
  `mdp_client` varchar(254) DEFAULT NULL,
  `date_naiss` date DEFAULT NULL,
  `adresse1` varchar(254) DEFAULT NULL,
  `adresse2` varchar(254) DEFAULT NULL,
  `panier_en_cours` int(11) DEFAULT NULL,
  `last_connex` date DEFAULT NULL,
  `tph` varchar(254) DEFAULT NULL,
  `histo_nom_table` varchar(254) DEFAULT NULL,
  `id_droit` int(11) NOT NULL,
  PRIMARY KEY (`id_client`),
  KEY `FK_client_id_droit` (`id_droit`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Structure de la table `concat_art_menu`
--

CREATE TABLE IF NOT EXISTS `concat_art_menu` (
  `id_concat` int(11) NOT NULL AUTO_INCREMENT,
  `id_article` int(11) NOT NULL,
  `id_menu2` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_concat`),
  KEY `FK_concat_art_menu_id_menu2` (`id_menu2`),
  KEY `FK_concat_art_menu_id_article` (`id_article`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Structure de la table `droit`
--

CREATE TABLE IF NOT EXISTS `droit` (
  `id_droit` int(11) NOT NULL AUTO_INCREMENT,
  `role` varchar(254) DEFAULT NULL,
  PRIMARY KEY (`id_droit`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- Contenu de la table `droit`
--

INSERT INTO `droit` (`id_droit`, `role`) VALUES
(1, 'admin'),
(2, 'sudo'),
(3, 'client'),
(4, 'test');

-- --------------------------------------------------------

--
-- Structure de la table `menu1`
--

CREATE TABLE IF NOT EXISTS `menu1` (
  `id_menu1` int(11) NOT NULL AUTO_INCREMENT,
  `label_menu1` varchar(254) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`id_menu1`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Structure de la table `menu2`
--

CREATE TABLE IF NOT EXISTS `menu2` (
  `id_menu2` int(11) NOT NULL AUTO_INCREMENT,
  `label_menu2` varchar(254) CHARACTER SET utf8 DEFAULT NULL,
  `id_menu1` int(11) NOT NULL,
  PRIMARY KEY (`id_menu2`),
  KEY `FK_menu2_id_menu1` (`id_menu1`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Structure de la table `panier`
--

CREATE TABLE IF NOT EXISTS `panier` (
  `id_panier` int(11) NOT NULL AUTO_INCREMENT,
  `id_client` int(11) NOT NULL,
  `id_article` int(11) NOT NULL,
  `qte` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_panier`),
  KEY `FK_panier_id_client` (`id_client`),
  KEY `FK_panier_id_article` (`id_article`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Structure de la table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id_user` int(11) NOT NULL AUTO_INCREMENT,
  `id_droit` int(11) NOT NULL,
  `login_user` varchar(254) DEFAULT NULL,
  `mdp_user` varchar(254) DEFAULT NULL,
  PRIMARY KEY (`id_user`),
  KEY `FK_user_id_droit` (`id_droit`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;

--
-- Contenu de la table `user`
--

INSERT INTO `user` (`id_user`, `id_droit`, `login_user`, `mdp_user`) VALUES
(1, 1, 'root', 'root'),
(2, 2, 'admin', 'admin');

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `client`
--
ALTER TABLE `client`
  ADD CONSTRAINT `FK_client_id_droit` FOREIGN KEY (`id_droit`) REFERENCES `droit` (`id_droit`);

--
-- Contraintes pour la table `concat_art_menu`
--
ALTER TABLE `concat_art_menu`
  ADD CONSTRAINT `FK_concat_art_menu_id_article` FOREIGN KEY (`id_article`) REFERENCES `articles` (`id_article`),
  ADD CONSTRAINT `FK_concat_art_menu_id_menu2` FOREIGN KEY (`id_menu2`) REFERENCES `menu2` (`id_menu2`);

--
-- Contraintes pour la table `menu2`
--
ALTER TABLE `menu2`
  ADD CONSTRAINT `FK_menu2_id_menu1` FOREIGN KEY (`id_menu1`) REFERENCES `menu1` (`id_menu1`);

--
-- Contraintes pour la table `panier`
--
ALTER TABLE `panier`
  ADD CONSTRAINT `FK_panier_id_article` FOREIGN KEY (`id_article`) REFERENCES `articles` (`id_article`),
  ADD CONSTRAINT `FK_panier_id_client` FOREIGN KEY (`id_client`) REFERENCES `client` (`id_client`);

--
-- Contraintes pour la table `user`
--
ALTER TABLE `user`
  ADD CONSTRAINT `FK_user_id_droit` FOREIGN KEY (`id_droit`) REFERENCES `droit` (`id_droit`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
