{
	"controls": {
		"aggregation": {
			"auto": true,
			"period": "1m"
		},
		"timespan": {
			"magnitude": "hour",
			"mode": "relative",
			"period": "latest",
			"value": 24
		}
	},
	"description": "Office Energy consumption",
	"functions": "function x100(value, ts, series){\n    return value *100;\n}\n\nfunction KW2Cent(value, ts, series){\n    return value * 40;\n}\n\nfunction x10(value, ts, series){\n    return value * 10;\n}\n\nfunction decimals2(value, ts, series){\n    return parseFloat(value.toFixed(2));\n}",
	"name": "Office Energy consumption",
	"placeholders": {
		"sources": []
	},
	"properties": {
		"background_image": "#222222",
		"border_radius": "20px",
		"columns": 5,
		"row_height": 16
	},
	"tabs": [
		{
			"icon": "fas fa-tachometer-alt",
			"name": "80Tasmota",
			"widgets": [
				{
					"layout": {
						"col": 0,
						"row": 0,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Current"
					},
					"properties": {
						"color": "#ff8000",
						"decimal_places": 3,
						"icon": "",
						"size": "75px",
						"unit": "Amp",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "80Tasmota",
								"mapping": "ENERGY.Current",
								"tags": {}
							},
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 60,
								"mapping": "Current1",
								"resource": "measure",
								"update": "interval"
							},
							"name": "Source 1",
							"source": "device",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 8,
						"sizeX": 1,
						"sizeY": 24
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"majorTicks": 10,
						"max": 250,
						"min": 200,
						"plateColor": "#666666",
						"showValue": true,
						"textColor": "#1E313E",
						"tickColor": "#00ff00",
						"unit": "Volt"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "80Tasmota",
								"mapping": "ENERGY.Voltage",
								"tags": {}
							},
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"mapping": "Voltage1",
								"resource": "measure"
							},
							"name": "Source 1",
							"source": "device",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 1,
						"row": 0,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Voltage"
					},
					"properties": {
						"color": "#00ff00",
						"decimal_places": 1,
						"icon": "",
						"size": "75px",
						"unit": "Volt",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "80Tasmota",
								"mapping": "ENERGY.Voltage",
								"tags": {}
							},
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 60,
								"mapping": "Voltage1",
								"resource": "measure",
								"update": "interval"
							},
							"name": "Source 1",
							"source": "device",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 8,
						"sizeX": 1,
						"sizeY": 24
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"timespan": {
								"magnitude": "minute",
								"value": 5
							},
							"type": "timespan"
						},
						"showTs": true
					},
					"properties": {
						"majorTicks": 1,
						"max": 4,
						"min": 0,
						"plateColor": "#666666",
						"showValue": true,
						"textColor": "#000000",
						"tickColor": "#ff8000",
						"unit": "Ampere"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "80Tasmota",
								"mapping": "ENERGY.Current",
								"tags": {}
							},
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 60,
								"mapping": "Current1",
								"resource": "measure",
								"update": "interval"
							},
							"name": "Source 1",
							"source": "device",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 2,
						"row": 8,
						"sizeX": 1,
						"sizeY": 24
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"majorTicks": 100,
						"max": 600,
						"min": 0,
						"plateColor": "#666666",
						"showValue": true,
						"textColor": "#1E313E",
						"tickColor": "#00ffff",
						"unit": "Watt"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "80Tasmota",
								"mapping": "ENERGY.Power",
								"tags": {}
							},
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"mapping": "MeasPower1",
								"resource": "measure"
							},
							"name": "Source 1",
							"source": "device",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 1,
						"row": 85,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Energy Cost Total"
					},
					"properties": {
						"color": "#ffff00",
						"decimal_places": 0,
						"icon": "",
						"size": "75px",
						"unit": "Cent",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Total1",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"processing": {
								"input": "KW2Cent"
							},
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"api": {},
					"layout": {
						"col": 0,
						"row": 32,
						"sizeX": 3,
						"sizeY": 45
					},
					"panel": {
						"color": "#2f2f2f",
						"colors": [],
						"currentColor": "#2f2f2f",
						"currentSubtitle": "Office Energy consumption",
						"currentTitle": "Power",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Office Energy consumption",
						"title": "Power",
						"updateTs": 1727970111536
					},
					"properties": {
						"axis": true,
						"fill": false,
						"legend": true,
						"multiple_axes": false,
						"options": "var options = {\n    series: series,\n    chart: {\n        type: 'area'\n    },\n    dataLabels: {\n        enabled: false\n    },\n    stroke: {\n        curve: 'straight',\n        width: 1\n    },\n    xaxis: {\n        type: 'datetime',\n        labels: {\n            datetimeUTC: false\n        },\n        tooltip: {\n            enabled: true\n        }\n    },\n    yaxis: {\n        \"labels\": {\n            \"formatter\": function (val) {\n                return val.toFixed(2);\n            }\n        }\n    },\n    tooltip: {\n        x: {\n            format: 'dd/MM/yyyy HH:mm:ss'\n        }\n    }\n};",
						"xaxis": {
							"ticks": ""
						},
						"yaxis": {
							"max": 250,
							"min": 0,
							"ticks": 20
						}
					},
					"sources": [
						{
							"$timespan": {
								"magnitude": "hour",
								"mode": "configurable",
								"period": "latest",
								"value": 24
							},
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "MeasPower1",
								"tags": {}
							},
							"color": "#00ffff",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 10,
								"mapping": "MeasPower1",
								"resource": "measure",
								"update": "interval"
							},
							"name": "Effective Power",
							"processing": {
								"input": ""
							},
							"source": "bucket",
							"timespan": {
								"magnitude": "hour",
								"mode": "relative",
								"period": "latest",
								"value": 1
							}
						},
						{
							"$timespan": {
								"mode": "configurable"
							},
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Voltage1",
								"tags": {}
							},
							"color": "#2ecc71",
							"name": "Voltage",
							"source": "bucket",
							"timespan": {
								"magnitude": "hour",
								"mode": "relative",
								"period": "latest",
								"value": 1
							}
						},
						{
							"$timespan": {
								"magnitude": "hour",
								"mode": "configurable",
								"period": "latest",
								"value": 24
							},
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Today1",
								"tags": {}
							},
							"color": "#ff00ff",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 10,
								"mapping": "MeasPower1",
								"resource": "measure",
								"update": "interval"
							},
							"name": "Today's Energy (x100)",
							"processing": {
								"input": "x100"
							},
							"source": "bucket",
							"timespan": {
								"magnitude": "hour",
								"mode": "relative",
								"period": "latest",
								"value": 1
							}
						}
					],
					"type": "apex_charts"
				},
				{
					"layout": {
						"col": 2,
						"row": 0,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Power"
					},
					"properties": {
						"color": "#00ffff",
						"decimal_places": 1,
						"icon": "",
						"size": "75px",
						"unit": "Watt",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "80Tasmota",
								"mapping": "ENERGY.Power",
								"tags": {}
							},
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 60,
								"mapping": "MeasPower1",
								"resource": "measure",
								"update": "interval"
							},
							"name": "Source 1",
							"source": "device",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 93,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Energy today"
					},
					"properties": {
						"color": "#ff00ec",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "KW/h",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Today1",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 77,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Energy yesterday"
					},
					"properties": {
						"color": "#ff00ec",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "KW/h",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Yesterday1",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 85,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Energy total"
					},
					"properties": {
						"color": "#ff00ec",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "KW/h",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Total1",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 93,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Energy cost  today"
					},
					"properties": {
						"color": "#ffff00",
						"decimal_places": 0,
						"icon": "",
						"size": "75px",
						"unit": "Cent",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Today1",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"processing": {
								"input": "KW2Cent"
							},
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 77,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Energy Cost Yesterday"
					},
					"properties": {
						"color": "#ffff00",
						"decimal_places": 0,
						"icon": "",
						"size": "75px",
						"unit": "Cent",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Yesterday1",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"processing": {
								"input": "KW2Cent"
							},
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 77,
						"sizeX": 1,
						"sizeY": 24
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"title": "Outside Temperature"
					},
					"properties": {
						"color": "#00ffff",
						"gradient": true,
						"majorTicks": 10,
						"max": 35,
						"min": -5,
						"plateColor": "#555555",
						"showValue": true,
						"textColor": "#00ffff",
						"tickColor": "#000000",
						"unit": "°C"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "temperature",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 3,
						"row": 0,
						"sizeX": 1,
						"sizeY": 24
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"title": "Outside Humidity"
					},
					"properties": {
						"color": "#00ffff",
						"gradient": true,
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#555555",
						"showValue": true,
						"textColor": "#00ffff",
						"tickColor": "#000000",
						"unit": "% DewPoint"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "humidity",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 3,
						"row": 24,
						"sizeX": 1,
						"sizeY": 24
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"title": "Air Pressure"
					},
					"properties": {
						"color": "#00ffff",
						"gradient": true,
						"majorTicks": 25,
						"max": 1100,
						"min": 900,
						"plateColor": "#555555",
						"showValue": true,
						"textColor": "#00ffff",
						"tickColor": "#000000",
						"unit": "hPa"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "pressure",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 3,
						"row": 71,
						"sizeX": 1,
						"sizeY": 6
					},
					"panel": {
						"color": "#555555",
						"currentColor": "#555555",
						"showOffline": {
							"type": "none"
						},
						"title": "N_____________ E______________ S_____________W_____________N"
					},
					"properties": {
						"icon": "",
						"iconSize": "",
						"max": 360,
						"min": 0
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "direction",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "progressbar"
				},
				{
					"layout": {
						"col": 3,
						"row": 48,
						"sizeX": 1,
						"sizeY": 23
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"title": "Wind Speed"
					},
					"properties": {
						"color": "#00ffff",
						"gradient": true,
						"majorTicks": 5,
						"max": 25,
						"min": 0,
						"plateColor": "#555555",
						"showValue": true,
						"textColor": "#00ffff",
						"tickColor": "#000000",
						"unit": "m/s"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "wind",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 2,
						"row": 77,
						"sizeX": 1,
						"sizeY": 24
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"title": "Room Temperature"
					},
					"properties": {
						"color": "#00ffff",
						"gradient": true,
						"majorTicks": 10,
						"max": 30,
						"min": 0,
						"plateColor": "#555555",
						"showValue": true,
						"textColor": "#00ffff",
						"tickColor": "#000000",
						"unit": "°C"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Temperature1",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "tachometer"
				},
				{
					"$loadAttemps": 300,
					"layout": {
						"col": 4,
						"row": 35,
						"sizeX": 1,
						"sizeY": 7
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"showTs": false,
						"subtitle": "",
						"title": "Auto   =         (Click to open)"
					},
					"properties": {
						"color": "#c0c0c0",
						"colors": [
							{
								"blink": false,
								"color": "#000000",
								"max": 1,
								"min": 0
							},
							{
								"blink": false,
								"color": "#00ff00",
								"max": 2,
								"min": 1
							}
						],
						"decimal_places": 0,
						"icon": "",
						"iconSize": "",
						"link": "http://192.168.188.15/tm?",
						"max": 2,
						"min": 0,
						"size": "44px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 2,
								"mapping": "Relay2_2fb",
								"resource": "feedback",
								"update": "interval"
							},
							"name": "Source 1",
							"skipCurrent": 1,
							"skipMeasures": 1,
							"source": "value",
							"value": "Tasmota Schedule"
						}
					],
					"type": "text"
				},
				{
					"$loadAttemps": 300,
					"layout": {
						"col": 4,
						"row": 7,
						"sizeX": 1,
						"sizeY": 7
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"showTs": true,
						"subtitle": "Office power",
						"title": "Relay 1 Refoss P11"
					},
					"properties": {
						"color": "#c0c0c0",
						"colors": [
							{
								"blink": false,
								"color": "#000000",
								"max": 1,
								"min": 0
							},
							{
								"blink": false,
								"color": "#00ff00",
								"max": 2,
								"min": 1
							}
						],
						"decimal_places": 0,
						"icon": "",
						"iconSize": "",
						"max": 2,
						"min": 0,
						"size": "25",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 2,
								"mapping": "Relay1_1fb",
								"resource": "feedback",
								"update": "interval"
							},
							"name": "Source 1",
							"skipCurrent": 1,
							"skipMeasures": 1,
							"source": "device",
							"value": 2
						}
					],
					"type": "led"
				},
				{
					"$loadAttemps": 300,
					"layout": {
						"col": 4,
						"row": 14,
						"sizeX": 1,
						"sizeY": 7
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"showTs": true,
						"subtitle": "Relay",
						"title": "Relay 2.1  Witty onboard LED"
					},
					"properties": {
						"color": "#c0c0c0",
						"colors": [
							{
								"blink": false,
								"color": "#000000",
								"max": 1,
								"min": 0
							},
							{
								"blink": false,
								"color": "#00ff00",
								"max": 2,
								"min": 1
							}
						],
						"decimal_places": 0,
						"icon": "",
						"iconSize": "",
						"max": 2,
						"min": 0,
						"size": "25",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 2,
								"mapping": "Relay2_1fb",
								"resource": "feedback",
								"update": "interval"
							},
							"name": "Source 1",
							"skipCurrent": 1,
							"skipMeasures": 1,
							"source": "device",
							"value": 2
						}
					],
					"type": "led"
				},
				{
					"layout": {
						"col": 4,
						"row": 0,
						"sizeX": 1,
						"sizeY": 7
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#000000",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit_size": "20px",
						"weight": "font-bold"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "Relays"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 28,
						"sizeX": 1,
						"sizeY": 7
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Relay 2_2",
						"title": "OFF_______AUTO_______ON"
					},
					"properties": {
						"max": 2,
						"min": 0,
						"step": 1
					},
					"sources": [
						{
							"device": {
								"id": "MQTT-THINGER",
								"resource": "tris2.2"
							},
							"source": "device"
						}
					],
					"type": "slider"
				},
				{
					"$loadAttemps": 300,
					"layout": {
						"col": 4,
						"row": 21,
						"sizeX": 1,
						"sizeY": 7
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"showTs": true,
						"subtitle": "Lights",
						"title": "Relay 2.2  Witty Rainbow LED"
					},
					"properties": {
						"color": "#c0c0c0",
						"colors": [
							{
								"blink": false,
								"color": "#000000",
								"max": 1,
								"min": 0
							},
							{
								"blink": false,
								"color": "#00ff00",
								"max": 2,
								"min": 1
							}
						],
						"decimal_places": 0,
						"icon": "",
						"iconSize": "",
						"max": 2,
						"min": 0,
						"size": "25",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 2,
								"mapping": "Relay2_2fb",
								"resource": "feedback",
								"update": "interval"
							},
							"name": "Source 1",
							"skipCurrent": 1,
							"skipMeasures": 1,
							"source": "device",
							"value": 2
						}
					],
					"type": "led"
				}
			]
		}
	],
	"widgets": []
}
