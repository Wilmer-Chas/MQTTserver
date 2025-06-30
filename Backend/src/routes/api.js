const express = require('express');
const router = express.Router();
const { pool } = require('../config/db');

// exposes API routes for frontend to use, connecting directly to the postgres database

router.get('/sensor-data', async (req, res) => {
  const { type, device_id, start, end, limit = 100 } = req.query;

  let conditions = [];
  let values = [];
  let counter = 1;           

  if (type) {
    conditions.push(`sensor_key = $${counter++}`);
    values.push(type);
  }

  if (device_id) {
    conditions.push(`device_id = $${counter++}`);
    values.push(device_id);
  }

  if (start) {
    conditions.push(`received_at >= $${counter++}`);
    values.push(start);
  }

  if (end) {
    conditions.push(`received_at <= $${counter++}`);
    values.push(end);
  }

  let query = 'SELECT * FROM sensor_data';

  if (conditions.length > 0) {
    query += ' WHERE ' + conditions.join(' AND ');
  }

  query += ` ORDER BY received_at DESC LIMIT $${counter}`;
  values.push(limit);

  try {
    const { rows } = await pool.query(query, values)
    res.json(rows);
  } catch (err) {
    console.error('[ERROR] /sensor-data:', err.message);
    res.status(500).json({ error: 'Internal server error' });
  }
});

module.exports = router;