-- Faça uma visão para armazenas a data, e o somatorio de todas as transações agrupadas por categoria.
-- Armazene também a quantidade de transações por categoria. 
-- Depois faça uma consulta a esta visão e liste somente a quantidade de transações por categoria, 
-- ordenados em ordem descrensente de numero de transações

CREATE OR REPLACE VIEW ex_1 AS
SELECT t.data, sum(p.valor) as soma, count(t.id) as quantidade
FROM transacao t INNER JOIN produto p
ON t.codproduto = p.codigoproduto INNER JOIN categoria c
ON p.categoria = c.id
GROUP BY t.data;

SELECT soma 
FROM ex_1
ORDER BY soma DESC;


DROP VIEW ex_1;



---------------- Criação de Usuario ----------------

CREATE USER aluno WITH PASSWORD '123456';

---------------- Contendeo Privilégios ----------------

GRANT SELECT ON categoria to aluno;
GRANT SELECT ON ex_1 to aluno;


SELECT * FROM categoria;

SELECT * FROM transacao;

SELECT * FROM ex_1;