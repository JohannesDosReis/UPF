--Exercicio 1

CREATE TABLE curso (
    codigoCurso int PRIMARY KEY,
    nome VARCHAR(40) NOT NULL,
    ch int NOT NULL,
    nroCreditos int,
    valorCredito DECIMAL(6,2) NOT NULL
);

CREATE TABLE disc_curs(
    curriculo int NOT NULL,
    curso int,
    disciplina int,
    FOREIGN KEY (curso) REFERENCES curso(codigoCurso),
    FOREIGN KEY (disciplina) REFERENCES disciplina(codigo),
    PRIMARY KEY (curso, disciplina, curriculo) -- chave composta
);


--Exercicio 2
ALTER TABLE professor ADD telefone VARCHAR(15) DEFAULT 'não informado';
-- or
ALTER TABLE professor ADD COLUMN telefone VARCHAR(15) DEFAULT 'não informado';
b
INSERT INTO professor VALUES (5, 'Atanajura', 'Mestre', '(55)9954-8975');
INSERT INTO professor VALUES (6, Isabel, "Mestre");


--Exercicio 3
ALTER TABLE disciplina ALTER COLUMN nome TYPE VARCHAR(200);
ALTER TABLE disciplina ALTER COLUMN nome SET NOT NULL; -- se não fosse not null 

--Exerciciop 4

ALTER TABLE aula RENAME COLUMN conteudo TO Conteudo_Programático;


-- Exercicio 5

SELECT *
FROM disciplina
WHERE num_creditos > 2
ORDER BY nome DESC

--Exercicio 6
-- faça o comando SQL para listar o código dos professores que ministram aulas no mês de agosto de 2018
SELECT matricula, data
FROM aula 
WHERE data BETWEEN '01/08/2018' AND '31/08/2018'
-- WHERE data >= '01/08/2018' AND data <= '31/08/2018'

-- Exercicio 7
-- Faça o comando sql para listar todos os dados das aulas com código de disciplina 10, 11, 12 e com 2 ou mais periodos de aula

SELECT *
FROM aula
WHERE disciplina in (10,11,12) AND numero_de_periodos >= 2;




-- Exercicio 8
-- Faça o comando SQL para listar o código dos professores, data, e hora de inicio das aulas que forma ministradas no dia 22, independente do mes e ano

SELECT disctnct-- distintos
 EXTRACT(day from data) -- estrair
FROM aula
where EXTRACT


SELECT matricula, data, hora_inicio
FROM aula
WHERE EXTRACT(day from data) = '10'


--Exercicio 9
-- Faça o comando SQL para listar a data e os conteúdos das aulas dos professores com código 10 e tenha ministardo o tema SQL
SELECT data, conteudo_programático 
FROM aula
WHERE matricula = '3' and conteudo_programático LIKE '%SQL%'


-- Exercicio 10
SELECT conteudo_programático
FROM aula
WHERE hora_inicio IS NULL OR numero_de_periodos IS NULL


-- Exercicio 11
-- Faça o comando SQl para listar o nome do curso, o valor do credito, e o valor do credito com 10% de desconto, 
-- o valor total do curso (credito x valor do credito) sem desconto

SELECT nome, valorcredito, (valorcredito * 0.9), nrocreditos * valorcredito
FROM curso  

