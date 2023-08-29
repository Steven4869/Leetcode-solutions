# Write your MySQL query statement below
SELECT Person.firstName, Person.lastName, Address.City, Address.state from Person LEFT JOIN Address ON Person.personId = Address.personId;