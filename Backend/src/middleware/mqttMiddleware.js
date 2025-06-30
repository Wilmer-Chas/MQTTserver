const { insertSensorData } = require('../services/sensorDataService');

async function handleMessage(topic, messageBuffer) {
  const message = messageBuffer.toString();

  const parts = topic.split('/');
  const [owner, project, sensor] = parts;

  console.log(`📡 Received from sensor:`, { owner, project, sensor, message });

  try {
    const inserted = await insertSensorData({ owner, project, sensor, message });
    console.log('Inserted into DB:', inserted);
  } catch (err) {
    console.error('DB insert failed:', err);
  }
}

module.exports = { handleMessage };

