CREATE DATABASE agenda_telefonica;
CREATE TABLE registros (
  email VARCHAR(200) PRIMARY KEY,
  nome VARCHAR(200),
  telefone_residencial VARCHAR(15),
  telefone_celular VARCHAR(15)
);

