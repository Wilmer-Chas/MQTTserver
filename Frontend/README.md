# React + Vite

This template provides a minimal setup to get React working in Vite with HMR and some ESLint rules.

Currently, two official plugins are available:

- [@vitejs/plugin-react](https://github.com/vitejs/vite-plugin-react/blob/main/packages/plugin-react) uses [Babel](https://babeljs.io/) for Fast Refresh
- [@vitejs/plugin-react-swc](https://github.com/vitejs/vite-plugin-react/blob/main/packages/plugin-react-swc) uses [SWC](https://swc.rs/) for Fast Refresh

## Expanding the ESLint configuration

If you are developing a production application, we recommend using TypeScript with type-aware lint rules enabled. Check out the [TS template](https://github.com/vitejs/vite/tree/main/packages/create-vite/template-react-ts) for information on how to integrate TypeScript and [`typescript-eslint`](https://typescript-eslint.io) in your project.


run program with 
npm run dev



/public                 # Static files (favicon, index.html, images, fonts, etc.)

/src
  /assets               # Images, fonts, icons, svgs, videos
  /components           # Reusable UI components (buttons, cards, inputs)
  /context              # React context providers for global state
  /hooks                # Custom React hooks for logic reuse
  /pages                # Page-level components (views or routes)
  /services             # API calls, data fetching logic, external services
  /styles               # Global and modular CSS/SCSS files, design tokens
  /theme                # Theme config (colors, fonts, light/dark mode)
  /types                # TypeScript interfaces and types
  /utils                # General helper functions/utilities
  App.jsx               # Root App component
  index.jsx             # Application entry point (ReactDOM.render)
  setupTests.js         # Testing setup if using Jest or similar

/package.json
/vite.config.js         # Vite config file for build and dev server customization<>


[Arduino] <--MQTT--> [MQTT Broker (cloud)]
    |                         ^
    |                         |
    |----HTTP(S) requests----> [Backend API server] <---> [Database]
                                       ^
                                       |
                               [Frontend Web Page]
                          (talks to backend API only)

Arduino is a client and only communicates with MQTT
MQTT is a public URL that needs to be accessible
Database is private on the same network as the backend server
Backend is a public URL that needs to be accessible
Frontend acts as a client that should be reachable by anyone



