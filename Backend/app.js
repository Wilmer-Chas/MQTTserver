const mqttListener = require('./mqtt/listener');
const { testConnection } = require('./database');

function start()
{
    testConnection();
    console.log('application starting...');

    const topics = [
    'myname/project1/sensor1'
    // 'myname/project1/sensor2',
    //'myname/project2/sensor+',
     //'myname/+/sensor+'
    ];

    mqttListener.init(topics);
}

/*start().catch((err) => {
  console.error('Failed to start app:', err);
});
*/


module.exports = { start };