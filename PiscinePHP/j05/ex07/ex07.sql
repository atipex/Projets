SELECT titre,resum FROM `film` where `resum` LIKE '%42%' OR `titre` LIKE '%42%' ORDER BY `duree_min` ASC;
