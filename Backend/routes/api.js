const express = require('express');
const router = express.Router();
const db = require('../database'); // adjust path as needed



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
    conditions.push(`timestamp >= $${counter++}`);
    values.push(start);
  }

  if (end) {
    conditions.push(`timestamp <= $${counter++}`);
    values.push(end);
  }

  let query = 'SELECT * FROM sensor_data';

  if (conditions.length > 0) {
    query += ' WHERE ' + conditions.join(' AND ');
  }

  query += ` ORDER BY timestamp DESC LIMIT $${counter}`;
  values.push(limit);

  try {
    const { rows } = await db.query(query, values);
    res.json(rows);
  } catch (err) {
    console.error('[ERROR] /sensor-data:', err.message);
    res.status(500).json({ error: 'Internal server error' });
  }
});

module.exports = router;