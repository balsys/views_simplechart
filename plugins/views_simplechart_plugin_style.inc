<?php

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render each item in an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class ViewsSimplechartPluginStyle extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['chart_title'] = array('default' => 'Simple Chart');
    $options['chart_axis_mapping'] = array('default' => '');
    $options['chart_type'] = array('default' => 'bar');
    $options['chart_legend_position'] = array('default' => 'bottom');
    $options['chart_width'] = array('default' => '400');
    $options['chart_height'] = array('default' => '300');

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['chart_title'] = array(
      '#title' => t('Chart Title'),
      '#type' => 'textfield',
      '#size' => '60',
      '#default_value' => $this->options['chart_title'],
    );
    $form['chart_axis_mapping'] = array(
      '#title' => t('Chart Axis Mapping'),
      '#type' => 'textfield',
      '#description' => t('Each axis need to be placed as comma(,) separtor.'),
      '#size' => '60',
      '#default_value' => $this->options['chart_axis_mapping'],
    );
    $form['chart_type'] = array(
      '#type' => 'radios',
      '#title' => t('Chart type'),
      '#options' => array('BarChart' => t('Bar Chart'),'PieChart' => t('Pie Chart'),'ColumnChart' => t('Column Chart')),
      '#default_value' => $this->options['chart_type'],
    );
    $form['chart_legend_position'] = array(
      '#type' => 'radios',
      '#title' => t('Chart Legend Position'),
      '#options' => array('left' => t('Left'),'right' => t('Right'),'top' => t('Top'),'bottom' => t('Bottom')),
      '#default_value' => $this->options['chart_legend_position'],
    );
    $form['chart_width'] = array(
      '#title' => t('Chart Width'),
      '#type' => 'textfield',
      '#size' => '60',
      '#default_value' => $this->options['chart_width'],
    );
    $form['chart_height'] = array(
      '#title' => t('Chart Height'),
      '#type' => 'textfield',
      '#size' => '60',
      '#default_value' => $this->options['chart_height'],
    );
  }
  
  function render() {
    $barchart = $this->render_fields($this->view->result);
    $chartdata[] = explode(',', $this->options['chart_axis_mapping']);
    foreach($barchart as $row) {
      $chartdata[] = array_values($row);
    }
    $chartdata = json_encode($chartdata, JSON_NUMERIC_CHECK);
    return theme('views_simplechart_graph', array('barchart' => $chartdata, 'metadata' => $this->options));
  }
}
