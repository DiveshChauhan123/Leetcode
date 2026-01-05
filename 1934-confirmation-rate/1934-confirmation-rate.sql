SELECT user_id,
       FLOOR(confirmation_rate * 100 + 0.5) / 100 AS confirmation_rate
FROM (
    SELECT user_id,
           CASE WHEN total = 0 THEN 0 ELSE confirmed / total END AS confirmation_rate
    FROM (
        SELECT s.user_id,
               SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END) AS confirmed,
               SUM(CASE WHEN c.action IS NOT NULL THEN 1 ELSE 0 END) AS total
        FROM Signups s
        LEFT JOIN Confirmations c
        ON s.user_id = c.user_id
        GROUP BY s.user_id
    ) t
) r;
