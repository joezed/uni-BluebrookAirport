var bannerboy = bannerboy || {};

/* Settings
================================================= */
bannerboy.settings = function(banner) {
	var corner_1 = bannerboy.createElement({backgroundColor: "#ff0000", left: 330, top: 187, width: 1, height: 1, parent: banner});
	var corner_2 = bannerboy.createElement({backgroundColor: "#ff0000", left: 240, top: -4, width: 2, height: 1, parent: banner});
	var corner_3 = bannerboy.createElement({backgroundColor: "#ff0000", left: 389, top: -29, width: 1, height: 1, parent: banner});
	var corner_4 = bannerboy.createElement({backgroundColor: "#ff0000", left: 494, top: 147, width: 1, height: 1, parent: banner});

	TweenMax.set(corner_1, {opacity: 0});
	TweenMax.set(corner_2, {opacity: 0});
	TweenMax.set(corner_3, {opacity: 0});
	TweenMax.set(corner_4, {opacity: 0});

	return {
		widthFactor: 1,
		heightFactor: 0.4,
		transformOrigin: "80%, 10%",
		corners: [
			corner_1,
			corner_2,
			corner_3,
			corner_4
		],
		txt: [1, 1, 1],
		txt_travel: {x: -19},
		set: {
			//
		}
	}
}