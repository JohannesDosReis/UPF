-- Criação da base de dados Escola
-- Comandos de definição de dados

-- NON-UPPERCASE 



CREATE TABLE professor ( -- or create table 
	matricula int PRIMARY KEY, 
	nome varchar(40) NOT NULL,
	titulacao character varying(40)
);

create table disciplina (
	codigo int,
	nome varchar(40) NOT NULL,
	num_creditos int,
	PRIMARY KEY(codigo) -- alternative
);


CREATE TABLE aula(
	id int,
	data date NOT NULL,
	hora_inicio time,
	numero_de_periodos int , 
	conteudo varchar(200) NOT NULL,
	PRIMARY KEY(id),
	matricula int, 
	disciplina int,
	-- Criando chave estrangeira
	FOREIGN KEY(matricula) REFERENCES professor(matricula)
);

-- CONSTRAINT pk_aula is opcional


-- Alterando tabelas 

ALTER TABLE aula ADD CONSTRAINT pk_aula PRIMARY KEY(id);
ALTER TABLE aula ADD CONSTRAINT fk_disciplina FOREIGN KEY(disciplina) REFERENCES disciplina(codigo);


-- excluindo a tabela professor

DROP TABLE professor; --não funciona pois algum argumento da tabala esta sendo utilizado 
-- para conseguir usar comando cascate