      function initMap() {
        var adeuni = {lat: -34.920603, lng: 138.60622769999998};
        var map = new google.maps.Map(document.getElementById('map'), {
          zoom: 10,
          center: adeuni,
        });
        
      }
     function addMarker(){
        var marker = new google.maps.Marker({
          position: adenui,
          map: map,
        });
         
        }
       function showKI(){
          var kangaroo = {lat: -35.7752426, lng: 137.2142417};
        var map = new google.maps.Map(document.getElementById('map'), {
          zoom: 20,
          center: kangaroo,
        });
      
