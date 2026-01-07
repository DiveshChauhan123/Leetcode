SELECT 
    ROUND(
        SUM(order_date = customer_pref_delivery_date) * 100.0 / COUNT(*),
        2
    ) AS immediate_percentage
FROM (
    SELECT 
        customer_id,
        MIN(order_date) AS first_order_date
    FROM Delivery
    GROUP BY customer_id
) f
JOIN Delivery d
  ON d.customer_id = f.customer_id
 AND d.order_date = f.first_order_date;
