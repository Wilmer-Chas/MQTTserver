const pool = require('../src/config/db');

(async () => {
  try {
    await pool.query('SELECT NOW()');
    console.log('✅ Database connection successful');
    process.exit(0);
  } catch (err) {
    console.error('❌ Database connection failed:', err);
    process.exit(1);
  }
})();
