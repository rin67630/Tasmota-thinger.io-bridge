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
	"functions": "function x100(value, ts, series){\n    return value *100;\n}\n\nfunction KW2Cent(value, ts, series){\n    return value * 40;\n}\n\nfunction x10(value, ts, series){\n    return value * 10;\n}\n\n",
	"name": "Office Energy consumption",
	"placeholders": {
		"sources": []
	},
	"properties": {
		"background_image": "#222222",
		"border_radius": "20px",
		"columns": 3,
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
							"type": "none"
						}
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
						"col": 2,
						"row": 83,
						"sizeX": 1,
						"sizeY": 9
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Grid-tie inverter",
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
					"layout": {
						"col": 0,
						"row": 32,
						"sizeX": 3,
						"sizeY": 42
					},
					"panel": {
						"color": "#2f2f2f",
						"colors": [],
						"currentColor": "#2f2f2f",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Office Energy consumption",
						"title": "Power"
					},
					"properties": {
						"axis": true,
						"fill": false,
						"legend": true,
						"multiple_axes": true,
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
								"mode": "configurable",
								"period": "latest",
								"value": 24
							}
						},
						{
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
								"mode": "configurable"
							}
						},
						{
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
							"name": "Today's Energy",
							"processing": {
								"input": "x100"
							},
							"source": "bucket",
							"timespan": {
								"magnitude": "hour",
								"mode": "configurable",
								"period": "latest",
								"value": 24
							}
						},
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MINUTE",
								"mapping": "Temperature1",
								"tags": {}
							},
							"color": "#0000a0",
							"name": "Temperature x10",
							"processing": {
								"input": "x10"
							},
							"source": "bucket",
							"timespan": {
								"mode": "configurable"
							}
						}
					],
					"type": "chart"
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
						"col": 1,
						"row": 92,
						"sizeX": 1,
						"sizeY": 9
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Grid-tie inverter",
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
						"col": 1,
						"row": 74,
						"sizeX": 1,
						"sizeY": 9
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Grid-tie inverter",
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
						"col": 1,
						"row": 83,
						"sizeX": 1,
						"sizeY": 9
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Grid-tie inverter",
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
						"col": 2,
						"row": 92,
						"sizeX": 1,
						"sizeY": 9
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Grid-tie inverter",
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
						"col": 2,
						"row": 74,
						"sizeX": 1,
						"sizeY": 9
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "Grid-tie inverter",
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
						"col": 0,
						"row": 74,
						"sizeX": 1,
						"sizeY": 27
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"title": "Room Temp"
					},
					"properties": {
						"majorTicks": 10,
						"max": 40,
						"min": -20,
						"plateColor": "#333333",
						"showValue": true,
						"textColor": "#fcfdfe",
						"tickColor": "#0000ff"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "80Tasmota",
								"mapping": "DS18B20.Temperature",
								"tags": {}
							},
							"color": "#1abc9c",
							"device": {
								"id": "MQTT-THINGER",
								"interval": 10,
								"mapping": "Temperature1",
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
				}
			]
		}
	],
	"widgets": []
}
