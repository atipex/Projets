SELECT COUNT(`date`) from historique_membre where CAST(`date` as CHAR) LIKE '____-12-24%' OR DATE(`date`) >= '20061030' AND DATE(`date`) <= '20070727';
