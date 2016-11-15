<div id="views-simplechart-<?php print $id ?>" class="<?php print $classes ?>">
  <script type="text/javascript">
    google.charts.setOnLoadCallback(function(){
      var data = new google.visualization.arrayToDataTable(<?php print $barchart;?>);
      var options = {
        'is3D':true,
        'legend':'<?php print $metadata['chart_legend_position'];?>',
        'title':'<?php print $metadata['chart_title'];?>',
        'width':<?php print $metadata['chart_width'];?>,
        'height':<?php print $metadata['chart_height'];?>
      };
      var container = document.getElementById('views-simplechart-graph-<?php print $id ?>');
      var chart = new google.visualization.<?php print $metadata['chart_type'];?>(container);
      chart.draw(data, options);
    });
  </script>
  <div id="views-simplechart-graph-<?php print $id ?>"></div>
</div>