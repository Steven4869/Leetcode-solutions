# Write your MySQL query statement below
select s.student_id, s.student_name, su.subject_name, COUNT(e.subject_name) AS attended_exams from Students as s CROSS JOIN Subjects as su 
LEFT JOIN Examinations as e ON s.student_id = e.student_id AND su.subject_name = e.subject_name GROUP BY s.student_id, su.subject_name ORDER BY s.student_id, su.subject_name;