.PHONY: build run stop logs deploy

build:
	cd frontend && npm install && npm run build
	docker build -t hoops-access .

run:
	docker run -d --name hoops-access --restart unless-stopped -p 8180:8180 hoops-access

stop:
	-docker stop hoops-access
	-docker rm hoops-access

logs:
	docker logs -f hoops-access

deploy: build stop run
