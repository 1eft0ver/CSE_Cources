DROP TABLE IF EXISTS grades;
CREATE TABLE grades (
  id varchar(45) NOT NULL,
  chinese int NOT NULL,
  math int NOT NULL,
  english int NOT NULL
) ;

INSERT INTO grades VALUES ('Akai',50,20,30),('Andy',55,30,50),('Annie',90,100,80),('Cookie',70,50,60),('Jim',62,58,73),('Judy',95,98,91),('Michael',5,6,90),('Mike',6,8,9),('Wolf',100,100,60),('Wei',70,70,80);