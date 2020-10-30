CREATE TABLE categoria (
    id integer NOT NULL Primary key,
    descricao character varying(30) NOT NULL
);

CREATE TABLE produto (
    codigoproduto integer NOT NULL Primary key,
    nome character varying(30),
    valor numeric(6,2),
    peso  numeric(6,2),
    categoria integer,
    FOREIGN KEY (categoria) REFERENCES categoria (id)
);

CREATE TABLE fornecedor (
    codigofornecedor integer NOT NULL Primary key,
    razaosocial character varying(15) NOT NULL,
    estado character varying(2)
);

CREATE TABLE transacao (
    id integer NOT NULL Primary key,
    codproduto integer NOT NULL,
    codfornecedor integer NOT NULL,
    data date,
    FOREIGN KEY (codproduto) REFERENCES produto (codigoproduto),
    FOREIGN KEY (codfornecedor) REFERENCES fornecedor (codigofornecedor)
);

INSERT INTO categoria VALUES (50,'Alimentícios');
INSERT INTO categoria VALUES (51,'Enlatados');
INSERT INTO categoria VALUES (52,'Congelados');
INSERT INTO categoria VALUES (53,'Embutidos');
INSERT INTO categoria VALUES (54,'Bebidas');

INSERT INTO produto(codigoproduto,nome,valor,categoria) VALUES (1,'Arroz Parabolizado',2.12,50);
INSERT INTO produto VALUES (2,'Leite',2.99,900,50);
INSERT INTO produto VALUES (3,'Peixe',3.49,500,52);
INSERT INTO produto VALUES (4,'Sorvete',9.99,900,52);
INSERT INTO produto VALUES (5,'Ervilha',3.88,250,51);
INSERT INTO produto VALUES (6,'Sardinha',7.50,100,51);
INSERT INTO produto VALUES (7,'Skol',1.49,250,54);
INSERT INTO produto VALUES (8,'Calabresa',8.99,1000,53);
INSERT INTO produto VALUES (9,'Bacon',3.11,500,53);
INSERT INTO produto VALUES (10,'Iogurte',4.61,560,50);

INSERT INTO fornecedor VALUES (10,'Cereais & Cia','RS');
INSERT INTO fornecedor VALUES (11,'Pesk aqui','SC');
INSERT INTO fornecedor VALUES (12,'PIA','RS');
INSERT INTO fornecedor VALUES (13,'Nestle');
INSERT INTO fornecedor VALUES (14,'Dbom');
INSERT INTO fornecedor VALUES (15,'Ambev');

INSERT INTO transacao VALUES (20,5,11,'27/01/2017');
INSERT INTO transacao VALUES (21,5,10,'28/02/2017');
INSERT INTO transacao VALUES (22,5,11,'06/03/2018');
INSERT INTO transacao VALUES (32,4,11,'06/03/2018');
INSERT INTO transacao VALUES (23,4,14,'20/04/2018');
INSERT INTO transacao VALUES (24,5,14,'26/03/2018');
INSERT INTO transacao VALUES (25,5,11,'24/01/2018');
INSERT INTO transacao VALUES (26,3,10,'04/04/2018');
INSERT INTO transacao VALUES (27,6,14,'11/05/2017');
INSERT INTO transacao VALUES (28,6,10,'22/05/2017');
INSERT INTO transacao VALUES (29,7,15,'15/05/2018');
INSERT INTO transacao VALUES (30,8,11,'15/05/2018');
INSERT INTO transacao VALUES (31,6,11,'15/05/2018');    
  -----------------------------------------------------------
-- Exercicio 1
-- Faça uma consulta para listar o nome e valor dos produtos, comercializados do mês de janeiro (independete do ano)
SELECT DISTINCT p.nome, p.valor
FROM produto p
LEFT JOIN transacao t ON p.codigoproduto = t.codproduto 
WHERE EXTRACT (month FROM t.data) = 1;

-- Exercicio 2
-- Listar o nome do produto e suas respectivas categoria em ordem alfábetica descrescente de categoria. Liste todas as categorias
SELECT p.nome, c. descricao
FROM produto p
RIGHT JOIN categoria c ON p.categoria = c.id 
ORDER BY c. descricao DESC;

SELECT *
from categoria;


-- Exercicio 3
-- Listar quantos dias passaram das datas da transacao até a data atual
SELECT *, CURRENT_DATE - data AS quantidade_de_dias
FROM transacao;


-- Exercicio 4
-- faça uma consulta para listar todos os fornecedores (razaosocial) e a data de suas transações . Liste todos os fornecedores, independente que não estão envolvidos em transações
SELECT f.razaosocial, t.data
FROM fornecedor f
LEFT JOIN transacao t ON f.codigofornecedor = t.codfornecedor 
GROUP BY  f.razaosocial, t.data
ORDER BY f.razaosocial ASC;

-- Exercicio 5
-- Listar os dados (nome, valor, peso) de todos os produtos  



---------------------- Aula 01/11 ----------------------

CREATE TABLE alimentos (
    codigo serial PRIMARY KEY,
    nome VARCHAR(30) NOT NULL,
    preco NUMERIC(10,2)
);

INSERT INTO alimentos (nome, preco) 
    (   SELECT nome, valor 
        FROM produto 
        WHERE valor > 7);


SELECT *
FROM alimentos



---------------- sequencias ----------------

CREATE SEQUENCE gera_codigos
start 500
increment 2;

-- or 
CREATE SEQUENCE gera_codigos
start with 500
increment by 2;


CREATE TABLE populacao (
    codigo int DEFAULT nextval('gera_codigos') PRIMARY KEY,
    nome VARCHAR(30) NOT NULL
);

INSERT INTO populacao(nome) VALUES ('Ana');
INSERT INTO populacao(nome) VALUES ('Bety');
INSERT INTO populacao(nome) VALUES ('Juliana');

SELECT * 
FROM populacao;



SELECT nextval('gera_codigos');

ALTER SEQUENCE gera_codigos RESTART WITH 800;


INSERT INTO populacao (nome) VALUES ('Bartolomeu')

DELETE
FROM populacao
where nome = 'Bartolomeu'

--------------- Exemplo de croos join ---------------

SELECT c.descricao, p.nome
from categoria c 
CROSS JOIN produto p

CREATE TABLE aluno (
    matricula int PRIMARY key,
    nome VARCHAR(30)
);

INSERT INTO aluno VALUES (10, 'Roberto Ferreira'), (11, 'Teonas Cheik');


CREATE TABLE curso (
    codigo INT,
    descricao varchar(30),
    curriculo INT,
    PRIMARY KEY(codigo, curriculo)
);

drop TABLE curso

DELETE
FROM cursos

INSERT INTO curso VALUES    (107, 'Ciência da Computação', 3844),
                            (107, 'Ciência da Computação', 3672), 
                            (107, 'Ciência da Computação',5666)



SELECT DISTINCT a.nome, c.descricao
FROM curso c CROSS JOIN aluno a


----------------- UNION -----------------
SELECT descricao
FROM categoria c
UNION ALL
SELECT p.nome
FROM produto p;

-- Mostra repetidos
SELECT descricao
FROM categoria c
UNION
SELECT p.nome
FROM produto p;





----------------------------- Funções de Agregação -----------------------------

SELECT count(*) AS QUANTOS, min(valor) as MENOR, max(valor) AS Maximo, sum(valor) AS SOMA, avg(valor) AS MEDIA
FROM produto;

-- group by

SELECT *
FROM produto;

SELECT peso, count(*) as QTD
FROM produto
GROUP BY peso
HAVING  count(*) >= 2 -- like where, but for aggregation function 
ORDER BY QTD DESC;


-- Exercicio 11
-- Listar os fornecedores que nunca transacionaram. Ordenados por razao social

SELECT f.razaosocial, count(t.id) as "Numero de Transações"
FROM fornecedor f
LEFT JOIN transacao t ON f.codigofornecedor = t.codfornecedor 
GROUP BY f.razaosocial
HAVING count(t.id) = 0
ORDER BY f.razaosocial DESC




-- Exercicio 12
-- Listar media de valor das transações, ordenadas por data

SELECT t.data, to_char(avg(p.valor), 'L99G999D99') AS "Valor Medio"
FROM transacao t
INNER JOIN produto p ON t.codproduto = p.codigoproduto
GROUP by t.data
ORDER BY t.data DESC;


-- Exercicios 13
-- Listar o nome da categoria , o total de produtos e o valor medio desses produtos

SELECT c.descricao, sum(p.valor) as "total", avg(p.valor) as "media"
FROM categoria c INNER JOIN produto p 
ON c.id = p.categoria
GROUP BY c.descricao;


-- Exercio 14
-- Listar a soma de todos os produtos da categoria Embutidos e Enlatados

SELECT c.descricao, sum(p.valor) as Soma
FROM produto p RIGHT JOIN categoria c
ON p.categoria = c.id
WHERE lower(c.descricao) = 'embutidos' OR lower(c.descricao) = 'enlatados'
GROUP BY c.descricao;



-- Exercicio 15
-- Listta o valor medio e a quantidade das transacoes, ordenadas por mes
SELECT to_char(avg(p.valor), 'L99G999D99') AS "valor medio" , count(t.id) AS "quatidade", EXTRACT(month from t.data) as mes
FROM transacao t INNER JOIN produto p
ON p.codigoproduto = t.codproduto
GROUP BY mes
ORDER BY mes ASC;

-- Exemmplo com case

SELECT to_char(avg(p.valor), 'L99G999D99') AS "valor medio" , count(t.id) AS "quatidade", 
CASE
    WHEN EXTRACT(month from t.data) = 1 THEN 'Janeiro'    
    WHEN EXTRACT(month from t.data) = 2 THEN 'Fevereiro'    
    WHEN EXTRACT(month from t.data) = 3 THEN 'Março'    
    WHEN EXTRACT(month from t.data) = 4 THEN 'Abril'    
    WHEN EXTRACT(month from t.data) = 5 THEN 'Maio'    
    WHEN EXTRACT(month from t.data) = 6 THEN 'Junho'    
    WHEN EXTRACT(month from t.data) = 7 THEN 'Julho'    
    WHEN EXTRACT(month from t.data) = 8 THEN 'Agosto'    
    WHEN EXTRACT(month from t.data) = 9 THEN 'Setembro'    
    WHEN EXTRACT(month from t.data) = 10 THEN 'Outubro'    
    WHEN EXTRACT(month from t.data) = 11 THEN 'Novembro'    
    WHEN EXTRACT(month from t.data) = 12 THEN 'Dezembro'
    ELSE 'Outro mes'    
END as mes
FROM transacao t INNER JOIN produto p
ON p.codigoproduto = t.codproduto
GROUP BY mes
ORDER BY mes ASC;


-- Exercicio 16
-- Listar quantas e o valor total das transações dos meses de abril e maio de 2018
-- Liste apenas aquelas com valor acima de 13.50

SELECT EXTRACT(month from t.data) as mes, count(t.id) as Quantidade, sum(p.valor) as total
FROM produto p INNER JOIN transacao t
ON p.codigoproduto = t.codproduto
WHERE EXTRACT(month from t.data) BETWEEN 4 and 5 AND EXTRACT(year from t.data) = 2018
GROUP BY mes
HAVING sum(p.valor) > 13.50;

-- Exercicio 17
-- Listar o nome e quantidade dos 3 produtos que estiveram masi envolvidos em transações
-- (3 produtos mais comercializados)

SELECT p.nome, count(p.codigoproduto) as quantidade
FROM produto p INNER JOIN transacao t
ON p.codigoproduto = t.codproduto
GROUP BY p.nome
ORDER BY quantidade DESC
LIMIT 3;