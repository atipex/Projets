SELECT etage_salle AS `etage`, SUM(nbr_siege) as `sieges` FROM salle ORDER BY `sieges` DESC;
