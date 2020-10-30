----------------- Visções -----------------
CREATE VIEW teste1 
AS SELECT p.nome, t.data
FROM produto p INNER JOIN transacao t
ON p.codigoproduto = t.codproduto
ORDER BY t.data

SELECT *
FROM teste1
WHERE nome = 'Ervilha'

CREATE VIEW teste2 AS
SELECT c.nome as categoria, p.nome as produto
FROM categoria c INNER JOIN produto p
ON c.id = p.categoria


CREATE MATERIALIZED VIEW teste03 AS
SELECT nome
FROM produto

SELECT *
from teste03

UPDATE produto
SET nome = 'Leite Integral'
WHERE codigoproduto = 2;

SELECT * FROM produto;
SELECT * FROM teste03;

REFRESH MATERIALIZED VIEW teste03;
SELECT * FROM teste03;