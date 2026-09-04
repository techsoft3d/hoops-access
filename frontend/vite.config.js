import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import tailwindcss from '@tailwindcss/vite'

export default defineConfig({
  plugins: [react(), tailwindcss()],
  base: '/hoops-access/',
  server: {
    proxy: {
      '/hoops-access/translate': {
        target: 'http://localhost:8180',
        rewrite: (path) => path.replace(/^\/hoops-access/, ''),
      },
    },
  },
})