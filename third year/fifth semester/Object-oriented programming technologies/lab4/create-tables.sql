CREATE TABLE TelephoneOperator (
    ID INT PRIMARY KEY,
    callerNumber INT,
    calledNumber INT,
    date DATE,
    time TIME,
    duration INT,
    costOneTariffUnit INT,
    billingUnit INT,
    costCall INT
);