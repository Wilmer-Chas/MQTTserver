# Use official lightweight Node.js image
FROM node:16-alpine

# Set working directory inside the container
WORKDIR /app

# Copy package.json and package-lock.json or yarn.lock
COPY package.json package-lock.json* ./

# Install dependencies using npm (adjust if you want yarn)
RUN npm install

# Copy the rest of your frontend code
COPY . .

# Expose Vite's default dev server port
EXPOSE 5173

# Run the Vite dev server
CMD ["npm", "run", "dev"]
