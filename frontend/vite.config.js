import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import tailwindcss from '@tailwindcss/vite'
import path from 'node:path'
import { fileURLToPath } from 'node:url'

const __dirname = path.dirname(fileURLToPath(import.meta.url))

export default defineConfig({
  plugins: [react(), tailwindcss()],
  resolve: {
    alias: {
      // EnvisionViewer.jsx and its helpers live in public/envision (kept there on
      // purpose), but files under publicDir are never processed by Vite's module
      // graph (no JSX/ESM transform). This alias lets us import them from src
      // while Vite still transforms them like any other source file.
      '@envision': path.resolve(__dirname, 'public/envision'),
    },
  },
})