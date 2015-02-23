<article<?php print $attributes; ?>>
  <?php if (!$page && $title): ?>
  <header>
    <?php print render($title_prefix); ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php print render($title_suffix); ?>
	<span id="siteseal"><script type="text/javascript" src="https://seal.godaddy.com/getSeal?sealID=Msb8DTT6ObaN8C032hcovFDVnoRBHMa4cbIpnOnkrV8HINueBTMUkM2G6Ctn"></script></span>
    
  </header>
  <?php endif; ?>
  <div class="node-inner">
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>  
  
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  
  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    
  </div>
  </div>
  <?php print render($content['comments']); ?>
</article>