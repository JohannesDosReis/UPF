DROP TABLE funcionarios CASCADE;
DROP TABLE departamentos CASCADE;
DROP TABLE cargos CASCADE;
DROP TABLE habilidades CASCADE;
DROP TABLE func_hab CASCADE;


CREATE TABLE departamentos (
    cod_dep INT PRIMARY KEY,
    nome VARCHAR(30),
    localizacao VARCHAR(100) NOT NULL CHECK (
        (localizacao = 'setor azul') OR
        (localizacao = 'setor branco') OR
        (localizacao = 'setor preto')
    )
);

CREATE TABLE cargos (
    cod_carg INT NOT NULL, 
    salario REAL NOT NULL CHECK (
        salario >= 954.00
    ), 
    descricao VARCHAR(40),
    PRIMARY KEY(cod_carg)
);


CREATE TABLE funcionarios (
    matricula INT,
    nome VARCHAR(20) NOT NULL,
    num_dep INT NOT NULL,
    data_nasc DATE NOT NULL CHECK (
        data_nasc > CURRENT_DATE
    ),
    cod_dep INT,
    cod_carg INT
);

ALTER TABLE funcionarios ADD CONSTRAINT pk_func PRIMARY KEY (matricula);
ALTER TABLE funcionarios ADD CONSTRAINT fk_dep FOREIGN KEY (cod_dep) REFERENCES departamentos (cod_dep);
ALTER TABLE funcionarios ADD CONSTRAINT fk_carg FOREIGN KEY (cod_carg) REFERENCES cargos (cod_carg);


CREATE TABLE habilidades ( 
    cod_hab INT PRIMARY KEY,
    descricao VARCHAR(200)
);

CREATE TABLE func_hab (
    matricula INT,
    cod_hab INT,
    data_form DATE DEFAULT CURRENT_DATE,
    PRIMARY KEY(matricula, cod_hab)
);

ALTER TABLE func_hab ADD CONSTRAINT fk_func FOREIGN KEY (matricula) REFERENCES funcionarios (matricula);
ALTER TABLE func_hab ADD CONSTRAINT fk_hab FOREIGN KEY (cod_hab) REFERENCES habilidades (cod_hab);


-- Exercicio 3


-- departamentos: cod_dep, nome, localizacao
INSERT INTO departamentos(cod_dep, nome, localizacao) VALUES (1, 'RH', 'setor branco');
INSERT INTO departamentos(cod_dep, nome, localizacao) VALUES (2, 'Financeiro', 'setor preto');
INSERT INTO departamentos(cod_dep, nome, localizacao) VALUES (3, 'TI', 'setor azul');

-- cargos: cod_carg, salario, descricao
INSERT INTO cargos(cod_carg, salario, descricao) VALUES (1, '1000.00', 'Administrador');
INSERT INTO cargos(cod_carg, salario, descricao) VALUES (2, '2000.00', 'Gerente');
INSERT INTO cargos(cod_carg, salario, descricao) VALUES (3, '3000.00', 'Programador');



-- funcionarios: matricula, nome, num_dep, data_nasc, cod_dep, cod_carg
INSERT INTO funcionarios(matricula, nome, num_dep, data_nasc, cod_dep, cod_carg) VALUES (101, 'Pedro', 1, '19/10/2018', 2, 2);
INSERT INTO funcionarios(matricula, nome, num_dep, data_nasc, cod_dep, cod_carg) VALUES (102, 'João', 2, '20/10/2018', 3, 3);
INSERT INTO funcionarios(matricula, nome, num_dep, data_nasc, cod_dep, cod_carg) VALUES (103, 'Maria', 1, '21/10/2018', 1, 1);


-- habilidades: cod_hab, descricao
INSERT INTO habilidades(cod_hab, descricao) VALUES (10, 'Comunicativo');
INSERT INTO habilidades(cod_hab, descricao) VALUES (11, 'Liderança');
INSERT INTO habilidades(cod_hab, descricao) VALUES (12, 'Trabalho em Equipe');



-- func_hab: matricula, cod_hab, data_form
INSERT INTO func_hab(matricula, cod_hab) VALUES (102, 11);
INSERT INTO func_hab(matricula, cod_hab) VALUES (103, 10);
INSERT INTO func_hab(matricula, cod_hab) VALUES (101, 12);


-- Exercicio 4
--  Faça o codigo SQL para listar o nome, salário eoo cargo de cada funcionário. Liste em ordem decrescente de salário

SELECT funcionarios.nome, cargos.salario, cargos.descricao
FROM funcionarios INNER JOIN cargos ON funcionarios.cod_carg = cargos.cod_carg
ORDER BY cargos.salario DESC 
-- or ORDER BY 3 DESC


-- Exercicio 5
-- Faça o código SQL para listar o nome dos funcionários, a 
-- data de formação e a descrição das habilidades daqueles que 
-- tiveram formações nos meses de janeiro e fevereiro

SELECT funcionarios.nome, func_hab.data_form, habilidades.descricao
FROM funcionarios
INNER JOIN func_hab ON funcionarios.matricula = func_hab.matricula
INNER JOIN habilidades ON func_hab.cod_hab = habilidades.cod_hab
WHERE EXTRACT(MONTH FROM func_hab.data_form) IN (01,02);

-- OR using apelido para tabela

SELECT f.nome, fh.data_form, h.descricao
FROM funcionarios f
INNER JOIN func_hab fh ON f.matricula = fh.matricula
INNER JOIN habilidades h ON fh.cod_hab = h.cod_hab
WHERE EXTRACT(MONTH FROM fh.data_form) IN (01,02);



-- Exercicio 6
-- Faça um codigo SQL para listar a matricla dos funcionários com salário maior que R$ 2.000,00 e menor que R$ 5.000,00
SELECT f.matricula, c.salario
FROM funcionarios f
INNER JOIN cargos c ON f.cod_carg = c.cod_carg
WHERE c.salario > 2000.00 AND c.salario < 5000.00;


-- Exercicio 7
-- Faça um Sql para atualaizar em 25 % o salário de todos os funcionários que são Gerentes


UPDATE cargos
SET salario = salario * 1.25
WHERE lower(descricao) = 'gerente';  


-- Exercicio 8
-- Faça o codigo SQL para listar todos os Departametos, independente se possuem funcionários alocados

SELECT d.nome, f.nome
FROM departamentos d 
LEFT JOIN funcionarios f ON d.cod_dep = f.cod_dep 
GROUP BY d.nome, f.nome


-- Exercicio 9
-- Faça um codigo SQP para listar todos os Cargos e departamentos que não possuem funcionairios

SELECT d.cod_dep, d.nome, c.cod_carg, c.descricao 
FROM departamentos d 
FULL JOIN funcionarios f ON d.cod_dep = f.cod_dep 
FULL JOIN cargos c ON f.cod_carg = c.cod_carg 
WHERE f.matricula IS NULL


-- Exercicio 10
-- Faça o codigo SQL para listar o cargo do Funcinario que possuem um habilidade especifica
SELECT c.descricao, h.descricao
FROM cargos c
INNER JOIN funcionarios f ON c.cod_carg = f.cod_carg
INNER JOIN func_hab fh ON f.matricula = fh.matricula
INNER JOIN habilidades h ON fh.cod_hab = h.cod_hab
WHERE lower(h.descricao) = 'liderança'





