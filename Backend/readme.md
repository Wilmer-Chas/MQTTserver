# Node.js Backend Server

A backend server built with Node.js that connects to:

- **MQTT Broker** for real-time messaging
- **PostgreSQL** for persistent data storage
- **Frontend Application** for client interaction

---

## ▶️ Running the Server

Run it with Docker — make sure to have an `.env` file in the project root for configuration.

### Locally

```bash
git clone https://github.com/your-username/your-repo.git
cd your-repo

# Build the Docker image
docker build -t backend-server .

# Run the container, mapping port 5000 and passing env variables
docker run --env-file .env -p 5000:5000 backend-server
``` 

## 🚀 Features

- MQTT integration using [mqtt.js](https://github.com/mqttjs/MQTT.js)
- PostgreSQL integration via [pg](https://node-postgres.com/)
- REST API/WebSocket endpoints to communicate with frontend
- Configurable via environment variables
- Modular and extensible architecture

---

### enviroment variables for backend
This is the typical structure for an env file that connects to the backend
    PG_HOST=localhost
    PG_PORT=3002
    PG_USER=*Hidden*
    PG_PASSWORD=*Hidden*
    PG_DATABASE=mqttDatabase

# MQTT broker service config
    MQTT_HOST=mqtt
    MQTT_PORT=1883
    MQTT_WS_PORT=9001

# Backend service config
    BACKEND_PORT=5000
    DATABASE_URL=postgres://${PG_USER}:${PG_PASSWORD}@${PG_HOST}:${PG_PORT}/${PG_DATABASE}
    MQTT_BROKER=mqtt://${MQTT_HOST}:${MQTT_PORT}


## 📁 Project Structure
- node_modules/           # Installed dependencies (auto-managed)
- scripts/                # Custom utility or setup scripts
- tests/                  # Test files (unit/integration)
- Dockerfile              # Docker setup for containerizing the app
- package.json            # Project metadata and dependencies
- package-lock.json       # Exact version lock for dependencies
- README.md               # Project documentation

- src/                    # Application source code
  - config/               # Environment and application configuration
  - controllers/          # Request handlers for various routes
  - integrations/         # External service integrations (e.g., MQTT, DB)
  - middleware/           # Custom Express middleware (e.g., logging, error handling)
  - models/               # Database models or schemas
  - routes/               # Route definitions and API endpoints
  - services/             # Business logic and core service functions
  - utils/                # Utility/helper functions
  - app.js                # Express app configuration
  - server.js             # Application entry point (starts server)
