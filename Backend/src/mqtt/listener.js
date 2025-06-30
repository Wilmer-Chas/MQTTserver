// mqtt/listener.js

const mqtt = require('mqtt');
const { handleMessage } = require('../middleware/mqttMiddleware');
const logger = require('../utils/logger');

let client;


function init(topics = []) {
  if (!Array.isArray(topics) || topics.length === 0) {
    throw new Error('MQTT listener requires at least one topic to subscribe to.');
  }

  client = mqtt.connect('mqtt://broker.hivemq.com');

  setupEventHandlers(topics);
}


function setupEventHandlers(topics) {
  client.on('connect', () => onConnect(topics));
  client.on('message', onMessage);
  client.on('error', onError);
}


function onConnect(topics) {
  logger.info('Connected to MQTT broker');

  topics.forEach((topic) => {
    client.subscribe(topic, (err) => {
      if (err) {
        logger.error(`Failed to subscribe to ${topic}:`, err);
      } else {
        logger.info(`Subscribed to topic: ${topic}`);
      }
    });
  });
}


function onMessage(topic, message) {
  handleMessage(topic, message);
}


function onError(err) {
  logger.error('MQTT error:', err);
}

module.exports = { init };
