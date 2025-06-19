# Use official lightweight Node.js image
FROM node:16-alpine

# Set working directory inside the container
WORKDIR /app

# Copy package.json and package-lock.json (if present)
COPY package*.json ./

# Install dependencies
RUN npm install

# Copy the rest of the backend source code
COPY . .

# Expose the port your backend listens on (adjust if different)
EXPOSE 5000

# Command to start your backend server
CMD ["node", "server.js"]

