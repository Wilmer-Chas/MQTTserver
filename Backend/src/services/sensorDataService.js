const pool = require('../config/db');

async function insertSensorData({ owner, project, sensor, message }) {
  const query = `
    INSERT INTO sensor_data (owner, project, sensor, message)
    VALUES ($1, $2, $3, $4)
    RETURNING *;
  `;
  const values = [owner, project, sensor, message];

  try {
    const res = await pool.query(query, values);
    return res.rows[0];
  } catch (err) {
    console.error('Error inserting sensor data:', err);
    throw err;
  }
}

module.exports = { insertSensorData };
