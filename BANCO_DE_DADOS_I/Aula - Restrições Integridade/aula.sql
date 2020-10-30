CREATE TABLE pessoa (
    id INTEGER,
    nome VARCHAR(30),
    codigoEquipe INTEGER
);

CREATE TABLE equipe (
    codigo INTEGER,
    descricao VARCHAR(30)
);

ALTER TABLE pessoa ADD CONSTRAINT pkPessoa PRIMARY KEY (id);
ALTER TABLE equipe ADD CONSTRAINT pkEquipe PRIMARY KEY (codigo);
ALTER TABLE pessoa ADD CONSTRAINT fkPessoa FOREIGN KEY (codigoEquipe) REFERENCES equipe(codigo);

INSERT INTO equipe VALUES (1, 'Gremio');
INSERT INTO equipe VALUES (2, 'Inter');


INSERT INTO pessoa VALUES (100, 'Luan', 1);
INSERT INTO pessoa VALUES (101, 'Damião', 2);
INSERT INTO pessoa VALUES (102, 'Everton', 1);


DELETE 
FROM equipe
WHERE codigo = 2

-- deletando a chave estrangeira
ALTER TABLE pessoa DROP CONSTRAINT fkPessoa;
-- recriando a chave estrangeira
ALTER TABLE pessoa ADD CONSTRAINT fkPessoa FOREIGN KEY (codigoEquipe) 
REFERENCES equipe(codigo) ON DELETE SET NULL ON UPDATE CASCADE;

UPDATE equipe
SET codigo = 500
WHERE codigo = 2;

SELECT *
FROM equipe;

SELECT *
FROM pessoa;


DELETE
FROM equipe
WHERE codigo = 500;






