import { useState, useEffect } from 'react';

export function useSensorData(pollInterval = 5000) {
  const [sensorData, setSensorData] = useState(null);
  const [error, setError] = useState(null);

  useEffect(() => {
    let isMounted = true;

    const fetchData = async () => {
      try {
        const res = await fetch('http://localhost:3000/api/sensor');
        const data = await res.json();
        if (isMounted) setSensorData(data);
      } catch (err) {
        if (isMounted) setError(err);
      }
    };

    fetchData();
    const interval = setInterval(fetchData, pollInterval);

    return () => {
      isMounted = false;
      clearInterval(interval);
    };
  }, [pollInterval]);

  return { sensorData, error };
}
