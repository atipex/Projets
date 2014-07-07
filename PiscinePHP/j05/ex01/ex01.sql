CREATE TABLE `ft_table`
(
	id INT NOT NULL AUTO_INCREMENT,
	login VARCHAR(9) NOT NULL DEFAULT 'toto',
	groupe ENUM('staff', 'student', 'other') NOT NULL,
	date_de_creation DATE NOT NULL,
	PRIMARY KEY (id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;
