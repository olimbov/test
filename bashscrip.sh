#!/bin/sh

#Run GrafanaServer
cd /home/vlad/grafana-7.5.1/bin./grafana-server 
sleep 3

#Run Prometheus
cd /home/vlad/prometheus-2.26.0-rc.0.linux-amd64./prometheus
sleep 3

#Run Node Exporter
cd /home/vlad/node_exporter-1.1.2.linux-amd64./node_exporter
sleep 3

#Run Loki
cd /home/vlad/Loki__and_Pormtail./loki_linux-amd64 -config.file loki-local.yaml
sleep 3

#Run Promtail
cd /home/vlad/Loki__and_Pormtail./promtail_linux-amd64 -config.file promtail-local.yaml
