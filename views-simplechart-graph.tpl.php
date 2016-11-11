<?php
$chartdata[] = explode(',', $metadata['chart_axis_mapping']);
foreach($barchart as $row) {
  $chartdata[] = array_values($row);
}
$chartdata = json_encode($chartdata,JSON_NUMERIC_CHECK);
?>

<div id="views-simplechart-<?php print $id ?>" class="<?php print $classes ?>">
  <script type="text/javascript">
    google.charts.setOnLoadCallback(function(){
      var data = new google.visualization.arrayToDataTable(<?php print $chartdata;?>);
      var options = {
        'is3D':true,
        'legend':'<?php print $metadata['chart_legend_position'];?>',
        'title':'<?php print $metadata['chart_title'];?>',
        'width':<?php print $metadata['chart_width'];?>,
        'height':<?php print $metadata['chart_height'];?>
      };
      var chart = new google.visualization.<?php print $metadata['chart_type'];?>(document.getElementById('views-simplechart-graph-<?php print $id ?>'));
      chart.draw(data, options);
    });
  </script>
  <div id="views-simplechart-graph-<?php print $id ?>"></div>
</div>