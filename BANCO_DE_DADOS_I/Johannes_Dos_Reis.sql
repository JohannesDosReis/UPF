-- Criar os comandos SQL para criação das tabelas 
    -- Usar diferentes formas de criação das chaves primária e estrangeiras; 
    -- Usar a opções de integridade referencial ON Delete e/ou ON Update (ao menos uma tabela)  
    -- Usar as cláusulas check, not null, unique e default 
    -- Depois de criada as tabelas, fazer um exemplo do comando alter table 

-- CHECK
-- NOT NULL
CREATE TABLE tipo (
    cod_tipo INT PRIMARY KEY,
    area varchar(1000) NOT NULL,
    modalidade VARCHAR(9) CHECK(    modalidade = 'Bolsas' OR
                                    modalidade = 'Estágios' OR
                                    modalidade = 'Empregos' OR
                                    modalidade = 'Trainee'  )
);


CREATE TABLE contato (
    cod_contato INT,
    telefone INT,
    e_mail VARCHAR(40),
    PRIMARY KEY (cod_contato)
);

CREATE TABLE endereco (
    cod_endereco INT,
    numero INT,
    rua VARCHAR(30),
    bairro VARCHAR(20),
    cidade VARCHAR(30),
    PRIMARY KEY(cod_endereco)
);

-- UNIQUE
-- ON DELETE SET
-- ON UPDATE
CREATE TABLE divulgador (
    cod_divulgador INT,
    nome VARCHAR(20) UNIQUE,
    descricao VARCHAR(200),
    cod_endereco INT,
    PRIMARY KEY (cod_divulgador),
    FOREIGN KEY (cod_endereco) REFERENCES endereco(cod_endereco) ON DELETE SET NULL ON UPDATE CASCADE
);

CREATE TABLE central (
    cod_central INT,
    site VARCHAR(30),
    cod_contato int,
    FOREIGN KEY (cod_contato) REFERENCES contato(cod_contato)
);
ALTER TABLE central ADD CONSTRAINT pk_central PRIMARY KEY(cod_central);

CREATE SEQUENCE codigos
start with 10000;

-- DEFAULT
CREATE TABLE oportunidade (
    cod_oportunidade INT DEFAULT nextval('codigos') PRIMARY KEY,
    aprovada BOOLEAN DEFAULT FALSE,
    requesitos VARCHAR(1000),
    salario REAL,
    beneficios VARCHAR(1000),
    descricao VARCHAR(1000),
    cod_contato INT,
    cod_tipo INT,
    cod_central INT,
    cod_divulgador INT
);
ALTER TABLE oportunidade ADD CONSTRAINT fk_contato FOREIGN KEY(cod_contato) 
REFERENCES contato(cod_contato) ON DELETE SET NULL ON UPDATE CASCADE;

ALTER TABLE oportunidade ADD CONSTRAINT fk_tipo FOREIGN KEY(cod_tipo) 
REFERENCES tipo(cod_tipo);

ALTER TABLE oportunidade ADD CONSTRAINT fk_central FOREIGN KEY(cod_central) 
REFERENCES central(cod_central);

ALTER TABLE oportunidade ADD CONSTRAINT fk_divulgador FOREIGN KEY(cod_divulgador) 
REFERENCES divulgador(cod_divulgador);

-- Alterar Tabeça usando alter table
ALTER TABLE contato ALTER COLUMN telefone TYPE VARCHAR(11);

-- Criar os comandos SQL para inserção de dados (pelo menos 5 registros em cada tabela) 

INSERT INTO tipo (cod_tipo, area, modalidade) VALUES (01, 'Administração', 'Bolsas');
INSERT INTO tipo (cod_tipo, area, modalidade) VALUES (02, 'Informatica/TI', 'Estágios');
INSERT INTO tipo (cod_tipo, area, modalidade) VALUES (03, 'Marketing', 'Empregos');
INSERT INTO tipo (cod_tipo, area, modalidade) VALUES (04, 'Engenharia', 'Estágios');
INSERT INTO tipo (cod_tipo, area, modalidade) VALUES (05, 'Saude', 'Bolsas');


INSERT INTO contato (cod_contato, telefone, e_mail) VALUES (1001, '54998657234', 'luizpedrov@gmail.com');
INSERT INTO contato (cod_contato, telefone, e_mail) VALUES (1002, '54984167320', 'arnaldoco@outlook.com');
INSERT INTO contato (cod_contato, telefone, e_mail) VALUES (1003, '54992012973', 'paulasouza@gmail.com');
INSERT INTO contato (cod_contato, telefone, e_mail) VALUES (1004, '54998865321', 'felipelopes@gmail.com');
INSERT INTO contato (cod_contato, telefone, e_mail) VALUES (1005, '54999800442', 'carlosvargas@outlook.com');
INSERT INTO contato (cod_contato, telefone, e_mail) VALUES (1212, '54999800442', 'cent_opr_upf@outlook.com');


INSERT INTO endereco (cod_endereco, numero, rua, bairro, cidade) VALUES (101, 102, 'Rua Fernando Lopes', 'Gloria', 'Marau');
INSERT INTO endereco (cod_endereco, numero, rua, bairro, cidade) VALUES (102, 20, 'Avenidade Marechal Luiz Filho', 'Vila Alegre', 'Carazinho');
INSERT INTO endereco (cod_endereco, numero, rua, bairro, cidade) VALUES (103, 598, 'Rua Sábia', 'São Sebastião', 'Passo Fundo');
INSERT INTO endereco (cod_endereco, numero, rua, bairro, cidade) VALUES (104, 315, 'Rua João Neto', 'Coqueiros', 'Não Me Toque');
INSERT INTO endereco (cod_endereco, numero, rua, bairro, cidade) VALUES (105, 225, 'Avenidade Brasil', 'Palmas', 'Coxilha');
INSERT INTO endereco (cod_endereco, numero, rua, bairro, cidade) VALUES (106, 220, 'Avenidade Beira Mar', 'Palmas', 'Coxilha');


INSERT INTO divulgador (cod_divulgador, nome, descricao, cod_endereco) VALUES (10, 'Luiz Pedro Vaz', 'Setor de RH Stara', 102);
INSERT INTO divulgador (cod_divulgador, nome, descricao, cod_endereco) VALUES (11, 'Arnaldo Correia', 'Gerente Softvar', 103);
INSERT INTO divulgador (cod_divulgador, nome, descricao, cod_endereco) VALUES (12, 'Santa Luz LTDA', 'Setor RH', 101);
INSERT INTO divulgador (cod_divulgador, nome, descricao, cod_endereco) VALUES (13, 'Coqueiros', 'Setor de Admistração', 104);
INSERT INTO divulgador (cod_divulgador, nome, descricao, cod_endereco) VALUES (14, 'Carlos Andre Vargas', 'Coordenador Projeto Now', 105);


INSERT INTO central (cod_central, site, cod_contato) VALUES (1010, 'centraloportunidadeupf.com.br', 1212);


INSERT INTO oportunidade (aprovada, requesitos, salario, beneficios, descricao, cod_contato, cod_tipo, cod_central, cod_divulgador) 
VALUES (TRUE, 'Liderança', 450, 'vale transporte' ,'Manutenção dos motores da fabrica', 1001, 04, 1010, 10);
INSERT INTO oportunidade (aprovada, requesitos, salario, beneficios, descricao, cod_contato, cod_tipo, cod_central, cod_divulgador) 
VALUES (FALSE, 'Disponibilidade de horario', 2000, 'vale alimentação', 'Publicidade em eventos a demanda', 1003, 03, 1010, 12);
INSERT INTO oportunidade (aprovada, requesitos, salario, beneficios, descricao, cod_contato, cod_tipo, cod_central, cod_divulgador) 
VALUES (TRUE, 'Java, Python, C++', 0.00, '', 'Criação e Manutenção de Aplicações', 1002, 02, 1010, 11);
INSERT INTO oportunidade (aprovada, requesitos, salario, beneficios, descricao, cod_contato, cod_tipo, cod_central, cod_divulgador) 
VALUES (TRUE, 'Graduado ou Cursando Administração', 3000, 'vale transporte', 'Gerenciar Fluxo de Caixa', 1004, 01, 1010, 13);
INSERT INTO oportunidade (aprovada, requesitos, salario, beneficios, descricao, cod_contato, cod_tipo, cod_central, cod_divulgador) 
VALUES (FALSE, 'Cursando 6 nivel ou superior medicina', 5000, 'vale aliemntação', 'Bolsa de aprendizagem', 1005, 05, 1010 , 14);




-- Criar 2 comandos de atualização de dados (explicar a finalidade dos comandos de atualização) 


-- oportunidades do divuldar do divulgador de cod 13 e com salario com salario superior a 2.000 foram suspensas
UPDATE oportunidade 
SET aprovada = FALSE 
WHERE salario > 2000 AND cod_divulgador = 13;


-- empresa mudou de endereco
UPDATE divulgador
SET cod_endereco = 106
WHERE cod_divulgador = 14;



-- Criar 3 consultas SQL – com Joins entre tabelas (explicar qual é a finalidade de cada consulta) 
    --  Cada consulta deve envolver pelo menos 3 tabelas 
    -- Usar os comandos inner, left, right e full joins 

-- Mostras todas as oportunidades da cidade de Passo Fundo
SELECT op.descricao
FROM oportunidade op RIGHT JOIN divulgador d
ON op.cod_divulgador = d.cod_divulgador RIGHT JOIN endereco e
ON d.cod_endereco = e.cod_endereco
WHERE lower(e.cidade) = 'passo fundo'


-- Mostrar quais os tipos de oportunidades que o divulgador Luiz Pedro Vaz disponibiliza
SELECT t.modalidade, t.area
FROM tipo t INNER JOIN oportunidade o
ON t.cod_tipo = o.cod_tipo INNER JOIN divulgador d
ON o.cod_divulgador = d.cod_divulgador
WHERE d.nome = 'Luiz Pedro Vaz'

-- Mostrar as areas com oportunidade em cidade de coxilha
SELECT t.area
FROM tipo t INNER JOIN oportunidade o
ON t.cod_tipo = o.cod_tipo INNER JOIN divulgador d
ON o.cod_divulgador = d.cod_divulgador INNER JOIN endereco e
ON d.cod_endereco = e.cod_endereco
WHERE lower(e.cidade) = 'coxilha'


-- Criar 1 subconsultas (explicar qual é a finalidade da consulta) 

-- Listas o contato e endereço de todas oportunidade com salario menor que o menor salario salario do divulgador Coqueiros
-- e que estao aprovadas para exibição

SELECT c.telefone, c.e_mail, e.numero, e.rua, e.bairro, e.cidade, o.salario
FROM contato c INNER JOIN oportunidade o
ON c.cod_contato = o.cod_contato INNER JOIN divulgador d
ON o.cod_divulgador = d.cod_divulgador INNER JOIN endereco e
ON d.cod_endereco = e.cod_endereco
WHERE o.salario < ALL (
    SELECT min(o.salario)
    FROM oportunidade o  INNER JOIN divulgador d
    ON o.cod_divulgador = d.cod_divulgador
    WHERE lower(d.nome) = 'coqueiros'
)


-- Criar 3 consultas usando funções de agregação – envolver mais de uma tabela. 
    -- 2 consultas devem envolver a cláusula Having; 
    -- Ao menos 1 consulta usar a cláusula order by 


-- Mostras a media dos salarios das oportunidades ordenadas por modalidade

SELECT avg(o.salario), t.modalidade
FROM oportunidade o INNER JOIN tipo t
ON t.cod_tipo = o.cod_tipo
GROUP BY t.modalidade
ORDER BY t.modalidade DESC


-- mostrar quais areas tem media de salario superior a media dos salarios
SELECT t.area, AVG(o.salario)
FROM oportunidade o INNER JOIN tipo t
ON t.cod_tipo = o.cod_tipo
GROUP BY t.area
HAVING AVG(o.salario) > (
    SELECT AVG(o.salario)
    FROM oportunidade o
)
ORDER BY AVG(o.salario) ASC


-- Mostrar as  cidades com menor menos de 3 oportunidades em alguma das modalidades
SELECT t.modalidade, e.cidade, count(o.cod_oportunidade)
FROM tipo t INNER JOIN oportunidade o
ON t.cod_tipo = o.cod_tipo INNER JOIN divulgador d
ON o.cod_divulgador = d.cod_divulgador INNER JOIN endereco e
ON d.cod_endereco = e.cod_endereco
GROUP BY t.modalidade, e.cidade
HAVING count(o.cod_oportunidade) < 3
ORDER BY count(o.cod_oportunidade) ASC



-- Criar 2 visões que envolvam várias tabelas (explicar a finalidade de cada consulta) 
    -- Explicar o motivo pela qual está criando as visões. 


-- Usuarios poderem ver todas as oportunidades disponiveis
CREATE VIEW default_user_view AS
SELECT o.descricao, o.beneficios, o.salario, o.requesitos, t.area, t.modalidade, e.numero, e.rua, e.bairro, e.cidade, c.telefone, c.e_mail
FROM tipo t INNER JOIN oportunidade o
ON t.cod_tipo = o.cod_tipo INNER JOIN contato c 
ON o.cod_contato = c.cod_contato INNER JOIN divulgador d
ON o.cod_divulgador = d.cod_divulgador INNER JOIN endereco e
ON d.cod_endereco = e.cod_endereco
WHERE o.aprovada = TRUE

-- Empresarios podem ver onde ha menor oferta de emprego em determidado local
CREATE VIEW quantity_view AS
SELECT t.modalidade, t.area, e.bairro, e.cidade, count(o.cod_oportunidade)
FROM tipo t INNER JOIN oportunidade o
ON t.cod_tipo = o.cod_tipo INNER JOIN divulgador d
ON o.cod_divulgador = d.cod_divulgador INNER JOIN endereco e
ON d.cod_endereco = e.cod_endereco
GROUP BY t.modalidade, t.area, e.bairro, e.cidade
ORDER BY count(o.cod_oportunidade), t.modalidade, t.area, e.bairro, e.cidade DESC

