SELECT
    ROUND(
        (SUM(CASE WHEN minimum_date = cp THEN 1 ELSE 0 END) / COUNT(*)) * 100,
        2
    ) AS immediate_percentage
FROM (
    SELECT
        MIN(order_date) AS minimum_date,
        (
            SELECT customer_pref_delivery_date
            FROM Delivery d2
            WHERE d2.customer_id = d1.customer_id
            ORDER BY d2.order_date
            LIMIT 1
        ) AS cp
    FROM Delivery d1
    GROUP BY customer_id
)x;