SELECT COUNT(id_abo) AS `nb_abo`, ROUND(AVG(prix),-1) AS moy_abo, SUM(duree_abo) AS ft FROM abonnement;
