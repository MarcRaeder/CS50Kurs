SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN(
SELECT movies.id FROM movies
JOIN people ON stars.person_id = people.id
JOIN stars ON movies.id = stars.movie_id
WHERE people.name = "Kevin Bacon" AND people.birth == 1958) 
AND people.name != "Kevin Bacon";
