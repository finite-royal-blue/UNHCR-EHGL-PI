<?php

/**
 * @file
 * Provides PostGIS Output Layer for the OpenLayers module.
 */

/**
 * Implements hook_openlayers_layers().
 */
function postgis_openlayers_layers() {
  $layers = array();
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'postgis_formatter_layer';
  $layer->title = t('PostGIS Output Layer');
  $layer->description = t('This layer is used by the PostGIS module to display geospatial data on a map, for example when viewing a node page.');
  $layer->data = array(
    'layer_type' => 'openlayers_layer_type_raw',
    'projection' => array('900913'),
    'features' => array(),
  );
  $layers[$layer->name] = $layer;
  return $layers;
}

