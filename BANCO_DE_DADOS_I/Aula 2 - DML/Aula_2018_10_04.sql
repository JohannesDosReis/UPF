-- FAZENDO INSERÇÃO DE DADOS OU CARGA DE DADOS

--Tabela Professor
INSERT INTO professor(matricula, nome, titulacao) VALUES (1, 'Juca', 'Especialista');

INSERT INTO professor(matricula, nome, titulacao) VALUES (2, 'Baltazar', 'Mestre');

INSERT INTO professor(matricula, nome, titulacao) VALUES (3, 'Ana', 'Doutora');

INSERT INTO professor VALUES (4, 'Bety', 'Graduada');


--Tabela Disciplina
INSERT INTO disciplina(codigo, nome, num_creditos)  VALUES(10,'Banco de Dados I', 4);

INSERT INTO disciplina(codigo, nome, num_creditos)  VALUES(11,'Projeto de Banco de Dados', 2);

INSERT INTO disciplina(codigo, nome, num_creditos)  VALUES(12,'Sistemas Operacionais', 4);

INSERT INTO disciplina(codigo, nome, num_creditos)  VALUES(13,'Arquitetura', 6);

INSERT INTO disciplina(codigo, nome)  VALUES(14,'TC I');


--Tabela Aula
INSERT INTO aula(id, data, hora_inicio, numero_de_periodos, conteudo, matricula, disciplina) VALUES(100, '04/10/2018', '14:00', 4, 'SQL', 3, 10);

INSERT INTO aula(id, data, hora_inicio, numero_de_periodos, conteudo, matricula, disciplina) 
VALUES(101, '10/08/2018', '19:20:00', 2, 'Processor e Transações', 3, 11);

INSERT INTO aula(id, data, hora_inicio, numero_de_periodos, conteudo, matricula, disciplina) 
VALUES(102, '14/07/2018', '16:00:00', 2, 'Sistemas de arquivos', 1, 12);

INSERT INTO aula(id, data, numero_de_periodos, conteudo, matricula, disciplina) 
VALUES(103, '04/10/2018', 2, 'Modelo ER', 2, 10);

INSERT INTO aula VALUES (104, '03/08/2018', '21:05:00', 2, 'Processos em DeadLook', 2, 13);



-- Remoção de Dados

DELETE 
FROM professor
WHERE UPPER (nome) = 'JUCA'

-- or

DELETE 
FROM professor
WHERE lower (nome) = 'juca' and matricula = 1
-- Não vai remover devido a restrição de integridade


DELETE 
FROM professor
WHERE lower (nome) = 'bety' and matricula = 4


--ATUALIZAÇÃO DE DADOS

UPDATE disciplina
SET nome = 'Arquitetura de Computadores'
WHERE codigo = 13