import { useSensorData } from '../hooks/useSensorData';

function Dashboard() {
  const { sensorData, error } = useSensorData();

  if (error) return <p style={{ color: 'red' }}>Error loading sensor data.</p>;

  return (
    <div style={{ padding: '2rem', fontFamily: 'sans-serif' }}>
      <h1>Arduino Sensor Dashboard</h1>
      {sensorData ? (
        <pre>{JSON.stringify(sensorData, null, 2)}</pre>
      ) : (
        <p>Loading sensor data...</p>
      )}
    </div>
  );
}

export default Dashboard;

