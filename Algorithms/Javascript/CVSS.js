let aVvals = [0.85, 0.62, 0.55, 0.2]
let aCvals = [0.77, 0.44]
let pRvals = [[0.85,0.85],[0.62,0.68],[0.27,0.5]]
let uIvals = [0.85, 0.62]
let CIAvals = [0, 0.22, 0.56]

$(document).ready(function () {
	var opts = {
		chart: {
			type: 'bar'
		},
		series: [{
			name: 'cvss score',
			data: [0, 0, 0]
		}],
		xaxis: {
			categories: ['Base', 'Impact', 'Exploitability']
		},
		yaxis:{
			min:0,
			max:10
		},
		fill: {
			colors: ['#BB2D3B']
		}
	}

	var chart = new ApexCharts(document.querySelector("#chart"), opts);
	chart.render();
	
	$("#cvssForm").submit(function (e) {
		e.preventDefault()

		let sC = $("#sC").val()

		let aV = $("#aV").val()
		aV = aVvals[aV - 1]

		let aC = $("#aC").val()
		aC = aCvals[aC - 1]

		let pR = $("#pR").val()
		pR = pRvals[pR - 1][sC - 1]

		let uI = $("#uI").val()
		uI = uIvals[uI - 1]
		
		let cF = $("#cF").val()
		cF = CIAvals[cF - 1]

		let iN = $("#iN").val()
		iN = CIAvals[iN - 1]

		let aVa = $("#aVa").val()
		aVa = CIAvals[aVa - 1]
		
		let ISSVal = parseFloat(1-((1-cF) * (1-iN) * (1-aVa)))

		let impactVal = 0
		if (sC == 1){
			impactVal = parseFloat((6.42 * ISSVal).toFixed(1))
		} else{
			impactVal = parseFloat(((7.52 * (ISSVal-0.029)) - (3.25*Math.pow((ISSVal-0.02),15))).toFixed(1))
		}
		
		let exploitVal = parseFloat((8.22 * aV * aC * pR * uI).toFixed(1))

		let baseVal = 0
		if (impactVal <= 0){
			baseVal = 0
		} else if (sC==1){
			baseVal = Math.min(parseFloat(impactVal + exploitVal),10).toFixed(1)
		} else{
			baseVal = Math.min(parseFloat(1.08*(impactVal + exploitVal)),10).toFixed(1)
		}

		console.log(baseVal)
		chart.updateSeries([{
			data: [baseVal,impactVal,exploitVal]
		}])
	});
})
