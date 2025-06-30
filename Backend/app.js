const mqttListener = require('./mqtt/listener');
const { testConnection } = require('./database');


const express = require('express');
const apiRoutes = require('./routes/api');

const cors = require('cors');

const app = express();
app.use(cors({
  origin: 'http://localhost:5173',  // frontend address
  methods: ['GET', 'POST', 'PUT', 'DELETE'],
}));

app.use(express.json());
// Use the API router
app.use('/api', apiRoutes);

app.get('/test-cors', (req, res) => {
  res.json({ message: 'CORS is working' });
});

const PORT = process.env.BACKEND_PORT || 5000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});


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


module.exports = { start };