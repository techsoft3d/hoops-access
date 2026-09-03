FROM ubuntu:24.04

RUN apt-get update && apt-get install -y nodejs npm && rm -rf /var/lib/apt/lists/*

WORKDIR /app/backend
COPY backend/package*.json ./
RUN npm install --omit=dev

COPY backend/ ./
COPY frontend/dist/ /app/frontend/dist/

EXPOSE 8180

CMD ["node", "server.js"]
