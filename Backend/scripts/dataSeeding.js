const { insertSensorData } = require('../src/database'); // adjust the path if needed

async function seed() {
  try {
    const dummyData = [
      { owner: 'user1', project: 'project1', sensor: 'temperature', message: '22.5' },
      { owner: 'user1', project: 'project1', sensor: 'humidity', message: '45.2' },
      { owner: 'user2', project: 'project2', sensor: 'temperature', message: '20.3' },
    ];

    for (const entry of dummyData) {
      const result = await insertSensorData(entry);
      console.log('Inserted:', result);
    }

    console.log('✅ Dummy data seeded successfully.');
    process.exit(0);
  } catch (err) {
    console.error('❌ Error seeding data:', err);
    process.exit(1);
  }
}

seed();
