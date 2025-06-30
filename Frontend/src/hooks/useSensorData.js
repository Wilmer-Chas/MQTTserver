import { useState, useEffect } from 'react';

function buildQueryString(params) {
  const query = new URLSearchParams();
  for (const key in params) {
    if (params[key]) query.append(key, params[key]);
  }
  return query.toString() ? `?${query.toString()}` : '';
}

async function fetchSensorData(baseUrl, filters) {
  const queryString = buildQueryString(filters);
  const res = await fetch(`${baseUrl}${queryString}`);
  if (!res.ok) throw new Error(`Error: ${res.status}`);
  return res.json();
}

export function useSensorData({
  pollInterval = 5000,
  filters = {},
} = {}) {
  const baseUrl = import.meta.env.VITE_API_URL || 'http://localhost:5000/api/sensor-data';

  const [sensorData, setSensorData] = useState(null);
  const [error, setError] = useState(null);

  useEffect(() => {
    let isMounted = true;

    async function getData() {
      try {
        const data = await fetchSensorData(baseUrl, filters);
        if (isMounted) {
          setSensorData(data);
          setError(null);
        }
      } catch (err) {
        if (isMounted) setError(err.message || 'Unknown error');
      }
    }

    getData();
    const interval = setInterval(getData, pollInterval);

    return () => {
      isMounted = false;
      clearInterval(interval);
    };
  }, [pollInterval, filters, baseUrl]);

  return { sensorData, error };
}
