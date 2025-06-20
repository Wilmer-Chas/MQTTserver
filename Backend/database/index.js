// db/index.js
const { Pool } = require('pg');
require('dotenv').config({ path: '../.env' });

const pool = new Pool({
  host: process.env.PG_HOST || 'localhost',
  port: process.env.PG_PORT || 5432,
  user: process.env.PG_USER,
  password: process.env.PG_PASSWORD,
  database: process.env.PG_DATABASE,
});

async function testConnection() {
  try {
    await pool.query('SELECT NOW()');
    console.log('✅ Database connection successful');
  } catch (error) {
    console.error('❌ Database connection failed:', error);
    process.exit(1); // Exit app if DB connection fails
  }
}

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

module.exports = {
  pool,
  testConnection,
  insertSensorData,
};

